#include <stdio.h>
int main(void)
{
        int N,a;
        scanf("%d",&N);
        a=N/111;
        if (N%111!=0)a++;
        printf("%d\n",a*111);
        return 0;
}
