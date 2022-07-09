#include "ap.h"
#include "hardware/structs/sio.h"


#ifdef __cplusplus
extern "C" {
#endif

void vApplicationMallocFailedHook( void )
{
	while(1);
}

void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{
	while(1);
}

void vApplicationTickHook( void )
{

}

#ifdef __cplusplus
}
#endif




void task1Thread(void *args)
{

	while(1)
	{
		printf("Task1 in %d\n", sio_hw->cpuid);
		vTaskDelay(100);
	}
}

void task2Thread(void *args)
{
	while(1)
	{
		printf("Task2 in %d\n", sio_hw->cpuid);
		vTaskDelay(100);
	}
}


void apInit()
{
	xTaskCreate(task1Thread, "task1Thread", 256, NULL, 1, NULL);
	xTaskCreate(task2Thread, "task2Thread", 256, NULL, 1, NULL);

	vTaskStartScheduler();
}


void apMain()
{
	while(1)
	{
		
	}
}