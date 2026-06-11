#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <math.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ll, ll> P;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define REP(i, n) for (ll i = 0; i < (n); ++i)
#define REPR(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define FOR(i, n, m) for (ll i = (n); i < (m); ++i)
#define FORR(i, n, m) for (ll i = (m) - 1; i >= (n); --i) 
#define FORE(x, xs) for (auto &x: (xs))
#define ALL(v) v.begin(), v.end()
#define ZERO(a) memset(a,0,sizeof(a))

const ll INF = 9223372036854775807;
const int MOD = 1000000007;
const double EPS = 1e-14;
const double PI = acos(-1);

const int MAX = 2e5;

int N, X;
int x[MAX];

ll calc(int c) {
  // int c = (hi+lo)/2; /// ゴミを捨てる回数
  int p = N/c + min(1, N%c); /// 一回の往復で拾う最大の量

  ll res = 1l*(c+N)*X; /// ゴミを拾って捨てるのに使うエネルギー

  REP (i, N) {
    int j = N-1-i;
    int y = i/c; /// 拾う前に持っているゴミの数
    if (y == 0) res += x[j]; /// 行き道のエネルギー
    else res += 1l*(y+1)*(y+1)*(x[j+c]-x[j]); /// 一つ前から移動するのに必要なエネルギー

    if (j < c) res += 1l*(y+2)*(y+2)*x[j]; /// そこからゴミ箱に行くのに必要なエネルギー
  }

  return res;
}

int main() {

  cin >> N >> X;
  REP (i, N) cin >> x[i];


  ll ans = INF;
  
  int lo = 0, hi = N;
  while (hi - lo > 1) {
    int mid = (hi+lo)/2;
    ll res1 = calc(mid);
    ll res2 = calc(mid+1);

    if (res1 < res2) {
      if (hi == mid+1) hi = mid;
      else hi = mid+1;
    }
    else if (lo == mid) lo = mid+1;
    else lo = mid;

    ans = min(ans, min(res1, res2));
  }
  

  cout << ans << endl;
  return 0;
}