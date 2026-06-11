#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x[3],d,e,a,b,c,f=0,g;
    scanf("%d%d%d",&a,&b,&c);
    x[0]=abs(a-b);
    x[1]=abs(b-c);
    x[2]=abs(a-c);
    sort(x,x+3);
    f=x[0]+x[1];
    printf("%d",f);
}
