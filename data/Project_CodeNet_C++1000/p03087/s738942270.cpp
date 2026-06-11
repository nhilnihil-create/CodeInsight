#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<int> counts(n, 0);
  vector<int> ls(n), rs(n);
  rep(i, q) { cin >> ls[i] >> rs[i]; }
  counts[0] = 0;
  for (int i = 1; i < n; i++) {
    if (s[i - 1] == 'A' && s[i] == 'C') {
      counts[i] += counts[i - 1] + 1;
    } else {
      counts[i] = counts[i - 1];
    }
  }
  rep(i, q) { cout << counts[rs[i] - 1] - counts[ls[i] - 1] << endl; }
  return 0;
}
