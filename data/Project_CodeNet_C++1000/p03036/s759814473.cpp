#include <stdio.h>
int main(void)
{
        int r,K,x,i;
        scanf("%d%d%d",&r,&K,&x);
        for(i=0;i<10;i++){
                x=x*r-K;
                printf("%d\n",x);
        }
        return 0;
}
