#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) (v).begin(), (v).end()
#define resz(v, ...) (v).clear(), (v).resize(__VA_ARGS__)
#define reps(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep(i, n) reps(i, 0, n)

template<class T1, class T2> void chmin(T1 &a, T2 b){if(a>b)a=b;}
template<class T1, class T2> void chmax(T1 &a, T2 b){if(a<b)a=b;}

using Pi = pair<int, int>;
using Tapris = tuple<int, int, int>;
using vint = vector<int>;

const int inf = 1LL << 55;
const int mod = 1e9 + 7;

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  int n;
  cin >> n;
  vint l(n), r(n);
  rep(i, n) cin >> l[i] >> r[i];
  sort(all(l));
  reverse(all(l));
  sort(all(r));
  int ans = 0;
  int sum = 0;
  rep(i, n) {
    sum += 2*l[i];
    chmax(ans, sum);
    sum -= 2*r[i];
    chmax(ans, sum);
  }
  sum = 0;
  rep(i, n) {
    sum -= 2*r[i];
    chmax(ans, sum);
    sum += 2*l[i];
    chmax(ans, sum);
  }
  cout << ans << endl;

  return 0;
}
