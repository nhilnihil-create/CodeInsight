#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
//#define MOD 998244353
#define MOD 1000000007

int main(){
    int n,m;
    cin>>n>>m;
    ll x[n],y[n],z[n],ans=0;
    rep(i,0,n)scanf("%lld %lld %lld",&x[i],&y[i],&z[i]);
    //全部正
    ll f1[n],t1=0;
    rep(i,0,n)f1[i]=x[i]+y[i]+z[i];
    sort(f1,f1+n,greater<ll>());
    rep(i,0,m)t1+=f1[i];
    ans=max(ans,t1);
    ll f2[n],t2=0;
    rep(i,0,n)f2[i]=x[i]*-1+y[i]+z[i];
    sort(f2,f2+n,greater<ll>());
    rep(i,0,m)t2+=f2[i];
    ans=max(ans,t2);
    ll f3[n],t3=0;
    rep(i,0,n)f3[i]=x[i]+y[i]*-1+z[i];
    sort(f3,f3+n,greater<ll>());
    rep(i,0,m)t3+=f3[i];
    ans=max(ans,t3);
    ll f4[n],t4=0;
    rep(i,0,n)f4[i]=x[i]+y[i]+z[i]*-1;
    sort(f4,f4+n,greater<ll>());
    rep(i,0,m)t4+=f4[i];
    ans=max(ans,t4);
    ll f5[n],t5=0;
    rep(i,0,n)f5[i]=x[i]*-1+y[i]*-1+z[i];
    sort(f5,f5+n,greater<ll>());
    rep(i,0,m)t5+=f5[i];
    ans=max(ans,t1);
    ll f6[n],t6=0;
    rep(i,0,n)f6[i]=x[i]*-1+y[i]+z[i]*-1;
    sort(f6,f6+n,greater<ll>());
    rep(i,0,m)t6+=f6[i];
    ans=max(ans,t6);
    ll f7[n],t7=0;
    rep(i,0,n)f7[i]=x[i]+y[i]*-1+z[i]*-1;
    sort(f7,f7+n,greater<ll>());
    rep(i,0,m)t7+=f7[i];
    ans=max(ans,t7);
    ll f8[n],t8=0;
    rep(i,0,n)f8[i]=x[i]*-1+y[i]*-1+z[i]*-1;
    sort(f8,f8+n,greater<ll>());
    rep(i,0,m)t8+=f8[i];
    ans=max(ans,t8);
    cout<<ans<<"\n";
    
}