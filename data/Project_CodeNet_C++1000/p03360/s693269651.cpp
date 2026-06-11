#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int a,b,c,k;
    scanf("%d%d%d%d",&a,&b,&c,&k);
    if  (b>a)   swap(a,b);
    if  (c>a)   swap(a,c);
    a*=1<<k;
    printf("%d\n",a+b+c);
    return 0;
}