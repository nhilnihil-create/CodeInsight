#include<bits/stdc++.h>
using namespace std;

int a,b,maxn;

int main()
{
    scanf("%d%d",&a,&b);
    maxn=max(a+b,a-b);
    maxn=max(maxn,a*b);
    printf("%d\n",maxn);
    return 0;
}