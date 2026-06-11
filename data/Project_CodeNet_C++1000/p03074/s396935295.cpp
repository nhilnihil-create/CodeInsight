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
  int n, k;
  string s;
  cin >> n >> k >> s;
  vector<int> num;
  if (s[0] == '0') num.push_back(0);
  for (int i = 0; i < s.size();) {
    int j = i;
    while (j < s.size() && s[j] == s[i]) ++j;
    num.push_back(j - i);
    i = j;
  }
  if (s[n - 1] == '0') num.push_back(0);
  vector<int> sum(num.size() + 1, 0);
  rep(i, num.size()) sum[i + 1] = sum[i] + num[i];
  int ans = 0;
  for (int left = 0; left < sum.size(); left += 2) {
    int right = min((int)sum.size() - 1, left + 2 * k + 1);
    ans = max(ans, sum[right] - sum[left]);
  }
  cout << ans << endl;
  return 0;
}
