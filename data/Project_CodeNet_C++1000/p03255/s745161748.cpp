#include<bits/stdc++.h>
using namespace std;
#define N 200005
typedef long long ll;
ll n,a[N],X,num[N],ans,sum[N];
ll check(ll seg)
{
    ll B=n/seg,ans=n*X+X*seg;memset(sum,0,sizeof(sum));
    for(ll i=1;i<=B;i++){
        sum[i]+=seg;
    }sum[B+1]+=n%seg;
    ll tmp=n;
    for(ll i=1;i<=B+1;i++){
        while(sum[i])sum[i]--,ans+=num[i]*a[tmp--];
    }return ans;
}
int main()
{
    scanf("%lld%lld",&n,&X);ans=1000000000000000000;
    num[1]=5;for(ll i=2;i<=n+1;i++)num[i]=i*2+1;
    for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
    if(n<=0){
        for (ll i=1;i<=n;i++){
            ans=min(ans,check(i));
            // cout<<check(i)<<endl;
        }
        cout<<ans;
    }else{
        ll l=1,r=n;
        while(l<=r){
            ll mid1=l+(r-l+1)/3,mid2=l+2*(r-l+1)/3;
            ll tmp1=check(mid1),tmp2=check(mid2);
            if(tmp1<tmp2)r=mid2-1,ans=min(ans,tmp1);
            else l=mid1+1,ans=min(ans,tmp2);
        }cout<<ans;
    }
    return 0;
}