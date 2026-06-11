#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 200000
#define LL long long
int n;
LL pos[MAXN+5],X,sum[MAXN+5],ans;
LL get_sum(int l,int r){return sum[r]-sum[l-1];}
int main()
{
    scanf("%d%lld",&n,&X);
    for(int i=1;i<=n;i++)
    {scanf("%lld",&pos[i]);sum[i]=pos[i]+sum[i-1];}
    ans=0x3f3f3f3f3f3f3f3f;
    for(int k=1;k<=(n+1)/2;k++)
    {
        int l=0,r=n;
        LL sum=0;
        for(int i=1;r>=1;i++)
        {
            l=max(r-k+1,1);
            if(i==1)sum+=5*get_sum(l,r);
            else sum+=(2*i+1)*get_sum(l,r);
            r=l-1;
            if(sum+k*X>ans)break;
        }
        ans=min(ans,sum+k*X);
    }
    printf("%lld",ans+n*X);
}