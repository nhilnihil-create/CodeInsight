#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
// typedef pair<ll, ll> P;
typedef pair<int, int> P;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

int main() {
  int n;
  cin >> n;
  int a[n];
  REP(i, n) cin >> a[i];
  vector<P> ans;
  P mx = P(a[0], 0);  // a_iのMax
  P mn = P(a[0], 0);  // a_iのMin
  REP(i, n) {
    mx = max(mx, P(a[i], i));
    mn = min(mn, P(a[i], i));
  }
  if (0 <= mx.first + mn.first) {  // |min| <= |max|
    REP(i, n) {
      ans.push_back(P(mx.second, i));
      a[i] += mx.first;
    }
    REP(i, n - 1) ans.push_back(P(i, i + 1));
  } else {  // |min| > |max|
    REP(i, n) {
      ans.push_back(P(mn.second, i));
      a[i] += mn.first;
    }
    RREP(i, n - 1) ans.push_back(P(i + 1, i));
  }
  cout << ans.size() << endl;
  REP(i, ans.size()) {
    cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
  }
  return 0;
}