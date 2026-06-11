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
#define ll unsigned long long int
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
const ll linf = 1LL << 60;
const double EPS = 1e-10;
const int mod = 1e9 + 7;

// solve
template <class T>bool chmax(T &a, const T &b){if(a < b){a = b; return 1;} return 0;}
template <class T>bool chmin(T &a, const T &b){if(a > b){a = b; return 1;} return 0;}

ll add(int i){
  if(i == 1)return 5;
  else return (2 * i + 1);
}

int main(int argc, char const* argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  ll X;
  cin >> n >> X;
  vector<ll> x(n), xsum(n, 0);
  rep(i, n)cin >> x[i];
  reverse(all(x));
  rep(i, n){
    xsum[i] = x[i];
    if(i > 0)xsum[i] += xsum[i-1];
  }
  ll res = linf;
  for(int k = 1; k <= n; k++){
    ll tmp = (ll)(n + k) * X;
    for(int i = 0; i < n; i += k){
      tmp += add(i / k + 1) * (xsum[min(i+k-1, n-1)] - (i > 0 ? xsum[i-1]: 0));
    }
    res = min(res, tmp);
  }
  cout << res << endl;
	return 0;
}
