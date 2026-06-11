#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;

  vector<int> seq;
  if (s[0] == '0') seq.push_back(0);
  int si = 0;
  for (int i = 1; i < n; ++i) {
    if (s[i] != s[i-1]) {
      seq.push_back(i-si);
      si = i;
    }
  }
  seq.push_back(n-si);
  if (s[s.size()-1] == '0') seq.push_back(0);

  vector<int> cum(seq.size()+1);
  cum[0] = 0;
  rep(i, seq.size()) cum[i+1] += cum[i] + seq[i];

  int ans = -1;
  int l = 0;
  int r = 2 * k + 1;
  while (r < cum.size()) {
    ans = max(ans, cum[r] - cum[l]);
    l += 2;
    r += 2;
  }
  if (ans == -1) ans = n;
  cout << ans << endl;
  return 0;
}