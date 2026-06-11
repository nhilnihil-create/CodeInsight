#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <time.h>
#include <list>

using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define reps(x,c) for(auto x:c)
#define all(x) begin(x), end(x)
#define pb(a) emplace_back(a) 
#define mp(a,b) make_pair((a),(b))
#define pl pair<ll,ll>
#define INF 2147483600
#define fi first
#define se second
#define dbg(x) cout << #x"="<< (x) << endl
#define dbgv(x) cout<<#x<<endl;reps(y,x){cout<<y<<" ";}cout<<endl

const long long MOD = 1000000007;
ll inv[100100];

void init_inv(){
  inv[1] = 1;
  FOR(i,2,100100){
    inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
  }
}

inline ll mod(ll a) {
    return (a % MOD + MOD) % MOD;
}

int main(){
  ll n;cin>>n;
  vector<ll> a(n+10);
  FOR(i,1,n+1)cin>>a[i];
  init_inv();
  
  vector<ll> inv_sum(n+10);
  inv_sum[0]=0;
  FOR(i,1,n+10)inv_sum[i]=mod(inv_sum[i-1]+inv[i]);
  
  ll n_e=1;
  FOR(i,1,n+1)n_e=mod(n_e*i);

  ll ans=0;
  FOR(i,1,n+1){
    ans=mod(ans+mod(mod(n_e*mod(inv_sum[i]+inv_sum[n-i+1]-1))*a[i]));
  }
  cout<<ans<<endl;
}