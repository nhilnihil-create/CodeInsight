#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define repr(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define ALL(a) (a).begin(), (a).end()
using ll = long long;
// using Graph = vector<vector<int>>;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ll LINF = 1LL << 60;

int main() {
  vector<int> cnt(4, 0);
  rep(i, 6) {
    int x;
    cin >> x;
    x--;
    cnt[x]++;
  }
  sort(ALL(cnt));
  if (cnt[0] == cnt[1] && cnt[2] == cnt[3])
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
