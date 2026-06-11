#include<stdio.h>

int main()

{

    int A,N,i,temp;

    scanf("%d %d",&A,&N);

    temp = A;

    if(N>0)
    {
        while(temp>500)
        {
            temp = temp - 500;
        }

        if(temp<=N)
        {

            printf("Yes\n");

        }

        else
        {

            printf("No\n");

        }
    }

    else
    {
       if(temp%500==0)
       {
          printf("Yes\n");
       }

       else
       {
          printf("No\n");
       }
    }

    return 0;

}
