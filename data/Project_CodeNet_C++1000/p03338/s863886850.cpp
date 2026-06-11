#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int ans = 0;
  for (int i = 1; i < n; i++) {
    vector<int> list(26);
    vector<bool> list2(26);
    for (int j = 0; j < n; j++) {
      if (j < i) {
        list[s[j] - 'a']++;
      } else {
        if (list[s[j] - 'a'] >= 1) list2[s[j] - 'a'] = true;
      }
    }
    ans = max(ans, (int)count(all(list2), true));
  }
  cout << ans << endl;
  return 0;
}