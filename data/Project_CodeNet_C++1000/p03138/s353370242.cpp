/*** keep hungry and calm CoolGuang!***/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include<stdio.h>
#include<algorithm>
#define debug(x) cout<<#x<<":"<<x<<endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const ll INF=1e18;
const int maxn=1e6+18;
const int mod=998244353;
inline bool read(ll &num)
{char in;bool IsN=false;in=getchar();if(in==EOF) return false;while(in!='-'&&(in<'0'||in>'9')) in=getchar();if(in=='-'){ IsN=true;num=0;}else num=in-'0';while(in=getchar(),in>='0'&&in<='9'){num*=10,num+=in-'0';}if(IsN) num=-num;return true;}
ll n,m,p;
ll st[100];
ll dp[100][2];///被限制 不被限制
int main()
{
    scanf("%lld%lld",&n,&m);
    ll sum=0;
    for(int i=1;i<=n;i++){
        ll x;read(x);
        for(ll k=0;k<=45;k++)
            if(x>>k&1ll) st[k]++;
        sum+=x;
    }
    if(m==0){
        printf("%lld\n",sum);
        return 0;
    }
    int f=0;
    int mx=log2(m);
    dp[mx][0]=st[mx]*(1ll<<mx);
    dp[mx][1]=(ll)(n-st[mx])*(1ll<<mx);
    ll ans=0;
    for(int k=mx+1;k<=45;k++)
        ans+=(1ll<<k)*st[k];
    for(ll k=mx-1;k>=0;k--){
        if(m>>k&1ll){
            dp[k][1]=dp[k+1][1]+(1ll<<k)*(n-st[k]);
            dp[k][0]=max(dp[k+1][1]+(1ll<<k)*st[k],dp[k][0]);///取0
            dp[k][0]=max(dp[k+1][0]+(1ll<<k)*st[k],dp[k][0]);
            dp[k][0]=max(dp[k+1][0]+(1ll<<k)*(n-st[k]),dp[k][0]);
        }
        else{
            dp[k][1]=dp[k+1][1]+(1ll<<k)*st[k];
            dp[k][0]=max(dp[k+1][0]+(1ll<<k)*st[k],dp[k][0]);
            dp[k][0]=max(dp[k+1][0]+(1ll<<k)*(n-st[k]),dp[k][0]);
        }
    }
    printf("%lld\n",max(dp[0][0],dp[0][1])+ans);
    return 0;
}
