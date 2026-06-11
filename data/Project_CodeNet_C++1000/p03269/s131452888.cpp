#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,mx=0,cnt=0;
    scanf("%d",&n);
    for(int i=0;i<=19;i++)
        if(n&(1<<i))mx=i,cnt++;
    printf("%d %d\n",mx+1,2*mx+cnt-1);
    for(int i=1;i<=mx;i++)printf("%d %d 0\n",i,i+1),printf("%d %d %d\n",i,i+1,1<<(i-1));
    int now=(1<<mx);
    for(int i=mx-1;i>=0;i--)
        if(n&(1<<i))printf("%d %d %d\n",i+1,mx+1,now),now+=(1<<i);
    return 0;
}