#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)  for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define pb push_back
typedef long long ll;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef priority_queue<ll> PQ;
typedef priority_queue<ll,vector<ll>,greater<ll>> SMALLPQ;
using vi=vector<ll>;
using vvi=vector<vector<ll>>;
using vc=vector<char>;
using vvc=vector<vector<char>>;
ll inf=1000000007;
const int MOD=998244353;
const int mod=998244353;
const int MAX=3001000;
void chmin(auto &a,auto b){if(b<a)a=b;}
void chmax(auto &a,auto b){if(a<b)a=b;}
vi fac,finv,inv;
void init(ll n) {
    fac=vi(n+5);finv=vi(n+5);inv=vi(n+5);
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    REP(i,2,n+5){
        fac[i]=fac[i-1]*i%mod;
        inv[i]=mod-inv[mod%i]*(mod/i)%mod;
        finv[i]=finv[i-1]*inv[i]%mod;
    }
}
long long modcom(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
} 

int main(){
  ll x,y,n,a,b,k;cin>>n>>a>>b>>k;
  ll ans=0;
  init(n);
  ll i=0;
  while(i<=n){
		if((k-i*a)%b!=0){
          i++;
          continue;
        }
		ll j=(k-i*a)/b;
		ans+=modcom(n,i)*modcom(n,j)%mod;
    	ans%=mod;
    	i++;
  }
  cout<<ans<<endl;
}
