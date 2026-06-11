#include <bits/stdc++.h>
using namespace std;
using i64 = int_fast64_t;

#define INF ((i64)(1e18))
#define MOD ((i64)(1e9+7))
#define REP(i, n) for(i64 i = 0; i < (n); i++)
#define RREP(i, n) for(i64 i = (n)-1; i >= 0; i--)
#define RANGE(i, a, b) for(i64 i = (a); i < (b); i++)
#define RRANGE(i, a, b) for(i64 i = (b)-1; i >= (a); i--)
#define ALL(v) (v).begin(), (v).end()
#define SIZE(v) ((i64)(v).size())
template<class T> inline void chmax(T &a, const T &b) { if (a < b) a = b; }
template<class T> inline void chmin(T &a, const T &b) { if (a > b) a = b; }

int main() {
  i64 n, a, b, c;
  cin >> n >> a >> b >> c;
  vector<i64> l(n);
  REP(i, n) cin >> l.at(i);
  sort(ALL(l));

  i64 ans = INF;
  do {
    RANGE(i, 0, n-2) {
      RANGE(j, i+1, n-1) {
        RANGE(k, j+1, n) {
          i64 sum1 = 0, sum2 = 0, sum3 = 0;
          RANGE(ii, 0, i+1) sum1 += l[ii];
          RANGE(jj, i+1, j+1) sum2 += l[jj];
          RANGE(kk, j+1, k+1) sum3 += l[kk];
          chmin(ans, abs(a-sum1)+abs(b-sum2)+abs(c-sum3)+10*(k+1)-30);
        }
      }
    }
  } while (next_permutation(ALL(l)));
  cout << ans << endl;

  return 0;
}
