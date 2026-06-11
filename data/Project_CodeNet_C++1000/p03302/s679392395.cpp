#include<bits/stdc++.h>
using namespace std;

int a,b;

int main()
{
    scanf("%d%d",&a,&b);
    if(a+b==15)
    {
        printf("+\n");
        return 0;
    }
    if(a*b==15)
    {
        printf("*\n");
        return 0;
    }
    printf("x\n");
    return 0;
}