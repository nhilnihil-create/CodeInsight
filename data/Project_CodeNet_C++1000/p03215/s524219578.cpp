//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
typedef long double lb;
#define int long long
#define double long double
#define endn "\n"
typedef pair<int,int> P;
template<class T> inline bool chmin(T& a, T b){if(a>b){a = b;return 1;}return 0;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a = b;return 1;}return 0;}
const int MOD = 1000000007;
//const int MOD = 998244353;
const ll INF = 1e16;
const double EPS = 1e-10;
const double PI = 3.141592653589793;
const string abc="abcdefghijklmnopqrstuvwxyz";
const string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 


////////////////////////////////////////////////////////////////////
///////////////////////___modpow___////////////////////
ll modpow(ll a,  ll n, const ll &MOD = MOD){
  ll ret = n == 0 ? 1 : modpow(a, n/2, MOD);
  (ret *= ret) %= MOD;
  if(n%2)((ret *= a) %= MOD);
  return ret;
}
///////////////////////___modinv___////////////////////
ll modinv(ll d, const ll &MOD = MOD){
  return modpow(d, MOD-2, MOD);
}
///////////////////////___combination___////////////////////
vector<ll> fac, finv, inv;
void COMinit(const int MAX = 5000000, const ll &MOD = MOD){
  fac.resize(MAX);finv.resize(MAX);inv.resize(MAX);
  fac[0] = fac[1] = finv[0] = finv[1] = inv[1] = 1;
  repd(i,2,MAX){
    fac[i] = fac[i-1] * i % MOD;
    inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
    finv[i] = finv[i-1] * inv[i] % MOD;
  }
}
ll COM(int n, int k){
  if(n < k)return 0;
  if(n < 0 || k < 0)return 0;
  return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD;
}

///////////////////////////////////////////////////////////
int n,k,a[1100];queue<int> q, r;
signed main(){
  cin>>n>>k;
  rep(i,n)cin>>a[i];
  int sum = 0;
  rep(i,n){
    sum = 0;
    repd(j,i,n){
      sum += a[j];
      q.push(sum);
    }
  }
  for(int i = 63;i >= 0;i--){
    q.push(-1);
    while(q.front() != -1){
      if(q.front()&(1LL<<i)){
        q.push(q.front());q.pop();
      }else{
        r.push(q.front());q.pop();
      }
    }
    q.pop();
    if(q.size() >= k){
      while(!r.empty()){
        r.pop();
      }
    }else{
      while(!r.empty()){
        q.push(r.front());r.pop();
      }
    }
  }
  
  int ans = ~0;
  rep(i,k){
    ans &= q.front();q.pop();
  }
  cout << ans << endl;
}

