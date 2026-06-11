#include<bits/stdc++.h>
using namespace std;
int h,w,n,a[200001],b[200001],mi[200001];
int main()
{
    scanf("%d%d%d",&h,&w,&n);
    int ans=h;
    memset(mi,125,sizeof(mi));
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]),mi[a[i]]=min(mi[a[i]],b[i]);
    int t=1;
    for(int i=2;i<=h;i++)
    {
        if(mi[i]<=t) {ans=i-1;break;}
        t=min(mi[i]-1,t+1);
    }
    printf("%d\n",ans);
}
