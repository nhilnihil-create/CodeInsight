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
const int mod = 1e9 + 7;

// solve
template <class T>bool chmax(T &a, const T &b){if(a < b){a = b; return 1;} return 0;}
template <class T>bool chmin(T &a, const T &b){if(a > b){a = b; return 1;} return 0;}

/*
 * f(U) = \sum_{U\in T}f(T)
 * for f(U) = \sum_{T\in U}f(T), use f[j | i] += f[j];
 */
template <typename T>
void fast_zeta(vector<T> &f){
  int n = f.size();
  for(int i = 1; i < n; i<<=1){
    for(int j = 0; j < n; j++){
      if((j & i) == 0){
        f[j | i] += f[j];
      }
    }
  }
}

struct pa{
  ll f, s;
  pa(ll f, ll s): f(f), s(s){}
  pa(){}
  pa & operator+=(const pa &r){
    ll tmp = f;
    f = max(f, r.f);
    s = max(tmp + r.f - f, max(s, r.s));
    return *this;
  }
};
int main(int argc, char const* argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pa> vec(1 << n);
  rep(i, (1 << n)){
    ll a;
    cin >> a;
    vec[i] = pa(a, 0);
  }
  fast_zeta(vec);
  ll curr = 0;
  for(int i = 1; i < (1 << n); i++){
    curr = max(curr, vec[i].f + vec[i].s);
    cout << curr << endl;
  }
	return 0;
}
