#include<stdio.h>

int main()
{
    long long int i,n, x, remind, num[100000],sum=0, save, max;

    scanf("%lld%lld", &n, &x);
    for(i = 0; i < n; i++)
    {
        scanf("%lld", &num[i]);
        sum+=num[i];

    }
    if(sum == x)
        printf("%lld\n",n);
    else
    {
       remind = x - sum;
      
       max = num[0];
        for(i =0; i < n; i++)
        {


            if(max > num[i])
                max = num[i];
        }
        save = remind / max;

        printf("%lld\n", n+save);
    }
    return 0;

   // }



}