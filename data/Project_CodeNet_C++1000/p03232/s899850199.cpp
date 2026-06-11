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

// macros
#define ll long long int
#define pb push_back
#define mk make_pair
#define pq priority_queue
#define FOR(i, a, b) for(int i=(a); i<(b);++i)
#define rep(i, n) FOR(i, 0, n)

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
const int mod = 1e9 + 7;

// solve
ll power(ll x, ll p){
  ll curr = x;
  ll res = 1;
  ll tmp = p;
  while(tmp){
    if(tmp % 2 == 1)res = res * curr % mod;
    curr = curr * curr % mod;
    tmp /= 2;
  }
  return res;
}

ll inv[100001];
ll fac[100001];

int main(int argc, char const* argv[])
{
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n)cin >> a[i];
  fac[0] = 1;
  FOR(i, 1, n+1)fac[i] = fac[i-1] * i % mod;
  FOR(i, 1, n+1){
    inv[i] = power(i, mod - 2);
  }
  FOR(i, 1, n+1){
    inv[i] = (inv[i] + inv[i-1]) % mod;
  }
  ll res = 0;
  rep(j, n){
    ll tmp = (inv[j+1] + inv[n-j] - 1) % mod;
    if(j == 0)tmp = inv[n];
    else if(j == n - 1)tmp = inv[n];
    if(tmp < 0)tmp += mod;
    res = (res + tmp * a[j] % mod) % mod;
  }
  cout << res * fac[n] % mod << endl;
	return 0;
}
