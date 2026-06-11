#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
ll dfs(string S, string now) {
  ll s = stoll(S), num;
  if (now == "") {
    num = 0;
  } else {
    num = stoll(now);
  }
  if (s < num) {
    return 0;
    /*bool ok3 = false, ok5 = false, ok7 = false;
    REP(i, now.size() - 1) {
      if (now[i] == '3') ok3 = true;
      if (now[i] == '5') ok5 = true;
      if (now[i] == '7') ok7 = true;
    }
    if (ok3 && ok5 && ok7) {
      REP(i, now.size() - 1) {
        // cout << now[i];
        // if (i == now.size() - 2) cout << endl;
      }
      return 1;
    }
    return 0;*/
  }
  ll ans = dfs(S, now + '3') + dfs(S, now + '5') + dfs(S, now + '7');
  bool ok3 = false, ok5 = false, ok7 = false;
  REP(i, now.size()) {
    if (now[i] == '3') ok3 = true;
    if (now[i] == '5') ok5 = true;
    if (now[i] == '7') ok7 = true;
  }
  if (ok3 && ok5 && ok7) {
    ans += 1;
  }
  return ans;
}
int main() {
  ll N;
  cin >> N;
  string S = to_string(N);
  ll ans = dfs(S, "");
  cout << ans << endl;
}