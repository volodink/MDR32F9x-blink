#include <MDR32F9x.h>


void PortB_Pin4_init(void){
  MDR_RST_CLK->PER_CLOCK |= (1UL << 22); // разрешение тактирования порта B

  MDR_PORTB->OE =     ((1 << 4)); //направление передачи данных = Выход
  MDR_PORTB->ANALOG = ((1 << 4)); //режим работы контроллера = 
  MDR_PORTB->FUNC =   ((0 << 4*2)); //режим работы вывода порта = 
  MDR_PORTB->PULL =   ((0 << 4)); //запрещение подтяжки к GND
  //MDR_PORTB->PULL =   ((0 << (4 << 16))); //запрещение подтяжки к VCC
  MDR_PORTB->PD =     ((0 << 4)); //режим работы выхода = 
  MDR_PORTB->PWR =    ((3 << 4*2)); //скорость фронта вывода = 
}

int main (void)
{
	unsigned int t=0;
	
	SystemInit();
	PortB_Pin4_init();
	while (1)
	{
		for (t=0; t<0xFFFFF; t++)
		MDR_PORTB->RXTX =0x00;
		for (t=0; t<0xFFFFF; t++)
		MDR_PORTB->RXTX =0xff;
	}
}
