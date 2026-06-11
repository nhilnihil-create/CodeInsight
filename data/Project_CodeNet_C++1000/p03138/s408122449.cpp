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

const int MAX_D = 60;
// dp[桁][未満フラグ]
ll dp[100][2];
int main() {
  int n;
  ll k;
  cin >> n >> k;
  vl A(n);
  rep(i, n) cin >> A[i];
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  rep(d, MAX_D) {
    ll mask = 1LL << (MAX_D - d - 1);
    int num = 0;
    rep(i, n) if (A[i] & mask) num++;

    ll score0 = mask * num;
    ll score1 = mask * (n - num);
    if (dp[d][1] != -1) maxs(dp[d + 1][1], dp[d][1] + max(score0, score1));
    if (dp[d][0] != -1) {
      if (k & mask) {
        maxs(dp[d + 1][0], dp[d][0] + score1);
        maxs(dp[d + 1][1], dp[d][0] + score0);
      } else {
        maxs(dp[d + 1][0], dp[d][0] + score0);
      }
    }
  }
  cout << max(dp[MAX_D][0], dp[MAX_D][1]) << endl;
  return 0;
}