#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <random>
#include <tuple>
#include <iomanip>
#include <cstring>

using namespace std;

typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define revrep(i, n) for(ll i = (n-1); i >= 0; i--)
#define pb push_back
#define f first
#define s second
const ll INFL = 1LL << 60;//10^18 = 2^60
const int INF = 1 << 30;//10^9
ll MOD = 1000000007;
//ll MOD  = 998244353;
vector<ll> dy = {0, 0, 1, -1, 1, 1, -1, -1, 0};
vector<ll> dx = {1, -1, 0, 0, 1, -1, 1, -1, 0};

ll max(ll a, ll b){return (a > b) ? a : b;}
ll min(ll a, ll b){return (a < b) ? a : b;}
ll pow_long(ll x, ll k){
  ll res = 1;
  while(k > 0){
    if(k % 2) res *= x;
    x *= x;
    k /= 2;
  }
  return res;
}
ll pow_mod(ll x, ll k){
  x %= MOD; x += MOD; x %= MOD;
  ll res = 1;
  while(k > 0){
    if(k % 2){
      res *= x; res %= MOD;
    }
    x *= x; x %= MOD;
    k /= 2;
  }
  return res;
}

ll inverse(ll x){return pow_mod(x, MOD - 2);};

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll x, ll y){return x / gcd(x, y) * y;};

ll kai_mod(ll x){
  if(x == 0) return 1;
  return x * kai_mod(x-1) % MOD;
}

//コンビネーション
const int MAXcomb = 200010;
ll fac[MAXcomb], finv[MAXcomb], inv[MAXcomb];
//facはn!,finvは1/n!
//invは逆元
void COMinit(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < MAXcomb; i++){
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}
ll comb(int n, int k){
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return fac[n] * finv[k] % MOD * finv[n-k] % MOD;
}


double solve(double s, double g, double mv, double t){
  double rs = mv - s;
  double rg = t - (mv - g);
  double res = 0;
  if(rs <= rg){
    res = mv * t;
    res -= rs * rs / 2;
    res -= (t - rg) * (t - rg) / 2;
  }else{
    double x, y;
    x = (-s + g + t) / 2;
    y = (s + g + t) / 2;
    res = y * t;
    res -= x * x / 2;
    res -= (t - x) * (t - x) / 2;
  }
  return res;
}


int main(){
  ll N; cin >> N;
  vector<double> T(N), maxV(N+1, 0);
  rep(i, N) cin >> T[i];
  vector<double> tmpMaxV(N);
  rep(i, N) cin >> tmpMaxV[i];
  rep(i, N-1) maxV[i+1] = min(tmpMaxV[i], tmpMaxV[i+1]);
  maxV[0] = 0, maxV[N] = 0;

  bool update = 1;
  while(update){
    update = 0;
    rep(i, N){
      if(maxV[i+1] > maxV[i] + T[i]){
        maxV[i+1] = maxV[i] + T[i];
        update = 1;
      }
    }
    revrep(i, N){
      if(maxV[i] > maxV[i+1] + T[i]){
        maxV[i] = maxV[i+1] + T[i];
        update = 1;
      }
    }
  }
  double ans = 0;
  rep(i, N){
    ans += solve(maxV[i], maxV[i+1], tmpMaxV[i], T[i]);
  }
  cout << fixed << setprecision(12) << ans << endl;

}
