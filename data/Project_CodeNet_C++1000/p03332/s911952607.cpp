#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf=998244353;
const int mod=998244353;
//Combination
long long extGCD(long long a,long long mod,long long &x,long long &y){
    if(mod==0){
        x=1;
        y=0;
        return a;
    }
    long long d=extGCD(mod,a%mod,y,x);
    y-=(a/mod)*x;
    return d;
}
long long invmod(long long a,long long mod){
    long long x,y;
    extGCD(a,mod,x,y);
    x%=mod;
    if(x<0)x+=mod;
    return x;
}
ll fac[300010],finv[300010],inv[300010];
void combinit(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    REP(i,2,300010){
        fac[i]=fac[i-1]*i%mod;
        inv[i]=invmod(i,mod);
        finv[i]=finv[i-1]*inv[i]%mod;
    }
}
ll comb(ll n,ll k){
    if(n<k)return 0;
    if(n<0||k<0)return 0;
    return fac[n]*(finv[k]*finv[n-k]%mod)%mod;
}
int main(){
    ll n,a,b,k;cin>>n>>a>>b>>k;
    combinit();
    ll ans=0;
    rep(i,n+1){
        if((k-a*i)%b==0&&(k-a*i)/b<=n){
            ans+=(comb(n,i)*comb(n,(k-a*i)/b));
            ans%=mod;
        }
    }
    cout<<ans<<endl;
}