#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
int main() {
  int N;
  cin >> N;
  vector<int> b(N);
  REP(i, N) cin >> b[i];
  vector<int> ans(0);
  while (b.size() >= 1) {
    bool t = false;
    for (int i = b.size() - 1; i >= 0; i--) {
      if (b[i] == i + 1) {
        t = true;
        ans.push_back(i + 1);
        b.erase(b.begin() + i);
      }
      if (t) break;
    }
    if (!t) {
      cout << -1 << endl;
      return 0;
    }
  }
  reverse(ans.begin(), ans.end());
  REP(i, ans.size()) { cout << ans[i] << endl; }
}