#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,t) for(int i=s;i<t;i++)
int isused[1<<17];
int main()
{
    int m,k;scanf("%d%d",&m,&k);
    if(k==0){
        rep(i,0,1<<m)printf("%d %d ",i,i);
        return 0;
    }
    if(m<2||k>=(1<<m)){printf("-1\n");return 0;}
    int co=0,nownum=0;
    while(co!=1<<m)
    {
        co+=4;int k1,k2,k3,k4;
        while(isused[nownum])nownum++;
        isused[nownum]=1,isused[k^nownum]=1;
        k2=nownum,k3=k^nownum;
        while(isused[nownum])nownum++;
        isused[nownum]=1,isused[k^nownum]=1;
        k1=nownum,k4=k^nownum;
        printf("%d %d %d %d %d %d %d %d ",k2,k4,k1,k2,k3,k1,k4,k3);
    }
}