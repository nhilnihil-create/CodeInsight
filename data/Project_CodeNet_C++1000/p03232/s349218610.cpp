#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define fr(i,x,n) for(int i=x;i<=n;i++)
#define rf(i,n,x) for(int i=n;i>=x;i--)
#define mst(x,i) memset(x,i,sizeof(x))
#define IOS ios::sync_with_stdio(false),cin.tie(0)
#define PB push_back
#define X first
#define Y second
#ifdef DBG
#define dbg(x...) do { cout << "\033[32;1m" << #x << " -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif
typedef long long LL;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int maxn=1E5+5;
const int maxm=1E5+5;
const int inf=0x3f3f3f3f;
const LL INF=0x3f3f3f3f3f3f3f3f;
const LL mod=1E9+7;
const double eps=1E-6;
const double PI=acos(-1.0);
template<class T>
bool scan(T &ret){
    char c;int sgn;
    if(c=getchar(),c==EOF) return 0;
    while(c!='-'&&(c<'0'||c>'9')) c=getchar();
    sgn=(c=='-')?-1:1;
    ret=(c=='-')?0:(c-'0');
    while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
    ret*=sgn;
    return 1;
}
template<class T>
T gcd(T a,T b){
    return b==0?a:gcd(b,a%b);
}
template<class T>
T qpow(T a,T b,T mod){
    T ret=1;
    a%=mod;
    while(b){
        if(b&1) ret=(a*ret)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ret%mod;
}
LL inv[maxn],sum[maxn],fac[maxn];
void init(int n){
    fac[0]=inv[0]=inv[1]=1;
    fr(i,2,n) inv[i]=((mod-mod/i)*inv[mod%i])%mod;
    rep1(i,n) sum[i]=(sum[i-1]+inv[i])%mod,fac[i]=1LL*fac[i-1]*i%mod;
}
void solve(){
    LL n,t;
    cin>>n;
    init(n);
    LL ans=0;
    rep1(i,n){
        cin>>t;
        ans=(ans+t*(sum[i]+sum[n-i+1]-1+mod)%mod)%mod;
    }
    ans=(ans%mod*fac[n]%mod)%mod;
    cout<<ans<<"\n";
}
int main(){
    IOS;
#ifdef LOCAL
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    clock_t START_TIME=clock();
#endif
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
#ifdef LOCAL
    clock_t END_TIME=clock();
    double time=double(END_TIME-START_TIME)/CLOCKS_PER_SEC;
    cout<<"\nprocess ends in "<<setprecision(4)<<time<<" seconds"<<endl;
#endif
    return 0;
}