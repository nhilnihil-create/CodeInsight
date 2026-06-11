// includes
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <functional>
#include <cmath>
#include <climits>
#include <bitset>
#include <list>
#include <random>

// macros
#define ll long long int
#define pb emplace_back
#define mk make_pair
#define pq priority_queue
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) for(int i=((int)(n)-1);i>=0;i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())

using namespace std;

//  types
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
typedef pair<ll, ll> Pll;
typedef pair<double, double> Pd;
 
// constants
const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;
const int mod = 998244353;

// solve
template <class T>bool chmax(T &a, const T &b){if(a < b){a = b; return 1;} return 0;}
template <class T>bool chmin(T &a, const T &b){if(a > b){a = b; return 1;} return 0;}

ll fac[300001], inv[300001];
template <typename T>
T power(T a, T n, T mod) {
  T res = 1;
  T tmp = n;
  T curr = a;
  while(tmp){
    if(tmp % 2 == 1){
      res = (T)((ll)res * curr % mod);
    }
    curr = (T)((ll)curr * curr % mod);
    tmp >>= 1;
  }
  return res;
}

int main(int argc, char const* argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  fac[0] = 1;
  for(int i = 1; i < 300001; i++)fac[i] = i * fac[i-1] % mod;
  inv[300000] = power<ll>(fac[300000], mod-2, mod);
  for(int i = 299999; i >= 0; i--)inv[i] = inv[i+1] * (i+1) % mod;
  int n;
  ll a, b, k;
  cin >> n >> a >> b >> k;
  ll res = 0;
  for(int i = 0; i <= n; i++){
    ll rem = k - (ll)i * a;
    if(rem % b != 0)continue;
    int j = rem / b;
    if(j > n || j < 0)continue;
    ll tmp = fac[n] * inv[i] % mod;
    tmp = tmp * inv[n-i] % mod;
    tmp = tmp * fac[n] % mod;
    tmp = tmp * inv[j] % mod;
    tmp = tmp * inv[n-j] % mod;
    res = (res + tmp) % mod;
  }
  cout << res << endl;
	return 0;
}
