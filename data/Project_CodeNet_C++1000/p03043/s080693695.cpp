#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(), a.end()
#define rrng(a) a.rbegin(), a.rend()
#define maxs(x, y) (x = max(x, y))
#define mins(x, y) (x = min(x, y))
#define limit(x, l, r) max(l, min(x, r))
#define lims(x, l, r) (x = max(l, min(x, r)))
#define isin(x, l, r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)), x.end())
#define show(x) cout << #x << " = " << x << endl;
#define print(x) cout << x << endl;
#define PQ(T) priority_queue<T, v(T), greater<T> >
#define bn(x) ((1 << x) - 1)
#define dup(x, y) (((x) + (y)-1) / (y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;

int main() {
  int n, k;
  cin >> n >> k;
  vi l(n + 1, -1), dice(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    dice[i] = i;
  }
  int cnt = 0, ok = 0;
  while (ok!=n) {
    for (int i = 1; i <= n; i++) {
      if (l[i] != -1) continue;
      if (dice[i] >= k) {
        l[i] = cnt;
        ok++;
      }
      dice[i] *= 2;
    }
    cnt++;
  }
  long double ans = 0,ave = 1.0/(long double)n;
  for(int i = 1;i<=n;i++){
    //show(l[i]);
    ans+= powf64x(0.5,l[i]);
  }
  printf("%.10Lf\n",ave*ans);
  return 0;
}