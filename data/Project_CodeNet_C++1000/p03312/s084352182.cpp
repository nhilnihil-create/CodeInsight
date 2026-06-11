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
 
// constants
const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;

// solve

int main(int argc, char const* argv[])
{
  int n;
  cin >> n;
  vector<ll> a;
  vector<ll> sum;
  rep(i, n){
    ll x;
    cin >> x;
    a.pb(x);
    if(i > 0)sum.pb(sum[i-1] + x);
    else sum.pb(x);
  }
  ll res = linf;
  FOR(i, 1, n - 2){
    ll b, c, d, e, bb, cc, dd, ee;
    int il = min(int(lower_bound(sum.begin(), sum.end(), (sum[i])/2) - sum.begin()), i - 1);
    b = sum[il];
    c = sum[i] - sum[il];
    if(il > 0){
      bb = sum[il-1];
      cc = sum[i] - sum[il-1];
      if(abs(bb - cc) < abs(b - c)){
        b = bb;
        c = cc;
      }
    }
    int ir = min(int(lower_bound(sum.begin(), sum.end(), (sum[n-1] - sum[i])/2 + sum[i]) - sum.begin()), n - 2);
    d = sum[ir] - sum[i];
    e = sum[n - 1] - sum[ir];
    if(ir > i+1){
      dd = sum[ir-1] - sum[i];
      ee = sum[n-1] - sum[ir-1];
      if(abs(dd - ee) < abs(d - e)){
        d = dd;
        e = ee;
      }
    }
    // cout << i << " " << b << " " << c << " " << d << " " << e << endl;
    res = min(res, max(b, max(c, max(d, e))) - min(b, min(c, min(d, e))));
  }
  cout << res << endl;
	return 0;
}
