#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=(1<<30)-1;
const int mod=998244353;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
const int nmax=300005;
ll fac[nmax],finv[nmax],inv[nmax];
void COMinit(){
  fac[0]=fac[1]=1;
  finv[0]=finv[1]=1;
  inv[1]=1;
  for(int i=2;i<nmax;i++){
    fac[i]=fac[i-1]*i%mod;
    inv[i]=mod-inv[mod%i]*(mod/i)%mod;
    finv[i]=finv[i-1]*inv[i]%mod;
  }
}
// modintを使うときはllをmintに
ll com(int n,int k){
  if(n<k||n<0||k<0){
    return 0;
  }
  return fac[n]*(finv[k]*finv[n-k]%mod)%mod;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,a,b,k;cin >> n >> a >> b >> k;
    ll ans=0;
    COMinit();
    for(ll i=0;i<=n&&i*a<=k;i++){
        if((k-i*a)%b==0){
            (ans+=com(n,i)*com(n,(k-i*a)/b)%mod)%=mod;
        }
    }
    cout << ans << endl;
}