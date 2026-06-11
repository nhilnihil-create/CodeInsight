#include<stdio.h>
int main()
{
    int n,a,b,c;
    scanf("%d%d",&n,&a);
    c=n%500;
    if(c==0||a>=n||c<a)
    {
        printf("Yes");

    }
    else

        {
            printf("No");
        }
    return 0;


}
