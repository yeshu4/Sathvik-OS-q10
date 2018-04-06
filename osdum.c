#include<stdio.h>
#include<conio.h>
int q1c,q2c;
int shortest_job_first();
int waiting_timepr[20];
int burst_timepr[20];
int main()
{
	printf("\n\t\tEnter number of processes in queue 1\t\t::\t\t");
	scanf("%d",&q1c);
	printf("\n\t\tEnter number of processes in queue 2\t\t::\t\t");
	scanf("%d",&q2c);
	int p1,p2;
	char name[3];
	while(1)
	{
	printf("\n\t\tEnter priority of queue 1\t\t::\t\t");
	scanf("%d",&p1);
	printf("\n\t\tEnter priority of queue 2\t\t::\t\t");
	scanf("%d",&p2);
	if(p1!=p2&&p1>p2)
	{
		break;
		
	}
	else
	{
		printf("ERROR \n error might be 1.priorities are equal\n2.priority of queue 1 has to be greater queue 2");
	}
}
shortest_job_first(q1c,1);
shortest_job_first(q2c,2);
}

int shortest_job_first(int a , int b) 
{
      int arrival_time[10], burst_time[10], temp[10];
      int i, smallest, count = 0, time, limit=a;
      double wait_time = 0, turnaround_time = 0, end;
      float average_waiting_time, average_turnaround_time;
      printf("\nEnter Details of processes in queue %d",b);
      for(i = 0; i < limit; i++)
      {
      		printf("\nprocess no %d ",i+1);
            printf("\nEnter Arrival Time:\t");
            scanf("%d", &arrival_time[i]);
            printf("Enter Burst Time:\t");
            scanf("%d", &burst_time[i]); 
            temp[i] = burst_time[i];
      }
      burst_time[9] = 9999;  
      for(time = 0; count != limit; time++)
      {
            smallest = 9;
            for(i = 0; i < limit; i++)
            {
                  if(arrival_time[i] <= time && burst_time[i] < burst_time[smallest] && burst_time[i] > 0)
                  {
                        smallest = i;
                  }
            }
            burst_time[smallest]--;
            if(burst_time[smallest] == 0)
            {
                  count++;
                  end = time + 1;
                  wait_time = wait_time + end - arrival_time[smallest] - temp[smallest];
                  turnaround_time = turnaround_time + end - arrival_time[smallest];
            }
      }
      average_waiting_time = wait_time / limit; 
      average_turnaround_time = turnaround_time / limit;
      printf("\n\nAverage Waiting Time:\t%lf\n", average_waiting_time);
      printf("Average Turnaround Time:\t%lf\n", average_turnaround_time);
      return 0;
}
