#include<iostream>
#include<cstdio>
using namespace std;
int h[105];
int main(void)
{
    int n,sum=0;
    scanf("%d" ,&n);
    for(int i=0;i<n;i++)
        scanf("%d" ,&h[i]);
    sum=h[0];
    for(int i=1;i<n;i++)
    {
        if(h[i]>h[i-1])
            sum+=h[i]-h[i-1];
    }
    printf("%d" ,sum);
    return 0;
}
