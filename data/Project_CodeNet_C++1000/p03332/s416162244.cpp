#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define P pair<ll,ll>
#define FOR(I,A,B) for(ll I = ll(A); I < ll(B); ++I)
#define FORR(I,A,B) for(ll I = ll((B)-1); I >= ll(A); --I)
#define TO(x,t,f) ((x)?(t):(f))
#define SORT(x) (sort(x.begin(),x.end())) // 0 2 2 3 4 5 8 9
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin()) //xi>=v  x is sorted
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin()) //xi>v  x is sorted
#define NUM(x,v) (POSU(x,v)-POSL(x,v))  //x is sorted
#define REV(x) (reverse(x.begin(),x.end())) //reverse
ll gcd_(ll a,ll b){if(a%b==0)return b;return gcd_(b,a%b);}
ll lcm_(ll a,ll b){ll c=gcd_(a,b);return ((a/c)*(b/c)*c);}
#define NEXTP(x) next_permutation(x.begin(),x.end())
const ll INF=ll(1e16)+ll(7);
const ll MOD=1000000007LL;
#define out(a) cout<<fixed<<setprecision((a))
//tie(a,b,c) = make_tuple(10,9,87);
#define pop_(a) __builtin_popcount((a))
ll keta(ll a){ll r=0;while(a){a/=10;r++;}return r;}


/*
  [x^k](x^A+x^(A+B)+x^B+1)^N
  = [x^k](x^A+1)^N(x^B+1)^N
  = sum(i+j=k) { [x^i](x^A + 1)^N * [x^j](x^B + 1)^N }
  = sum(i+j=k) { N_C_(i/A) * N_C_(j/B) }
  = sum(An+Bm=k) { N_C_n * N_C_m }

*/

class comb{
  vector<ll> f,fr;
  ll MOD_;
  public:
  //a^(p-1) = 1 (mod p)(p->Prime numbers)
  //a^(p-2) = a^(-1)
  ll calc(ll a,ll b,ll p){//a^(b) mod p   
    if(b==0)return 1;
    ll y = calc(a,b/2,p);y=(y*y)%p;
    if(b & 1) y = (y * a) % p;
    return y;
  }
  void init(ll n,ll mod){//input max_n
    MOD_ = mod;
    f.resize(n+1);
    fr.resize(n+1);
    f[0]=fr[0]=1;
    for(ll i=1;i<n+1;i++){
      f[i] = (f[i-1] * i) % mod;
    }
    fr[n] = calc(f[n],mod-2,mod);
    for(ll i=n-1;i>=0;i--){
      fr[i] = fr[i+1] * (i+1) % mod;
    }
  }
  ll nCr(ll n,ll r){
    if(n<0||r<0||n<r)return 0;
    return f[n] * fr[r] % MOD_ * fr[n-r] % MOD_;
  }//nHr = n+r-1Cr
};

int main(){

  ll N,A,B,K;
  cin >> N >> A >> B >> K;
  ll mod = 998244353;
  ll ans = 0;
  comb co;
  co.init(314159,mod);
  FOR(i,0,N+1){
    ll An = A*i;
    ll Bm = K - An;
    if(Bm % B != 0)continue;
    ll m = Bm/B;
    (ans += co.nCr(N,i) * co.nCr(N,m) % mod ) %= mod;
  }
  cout << ans << endl;
}
