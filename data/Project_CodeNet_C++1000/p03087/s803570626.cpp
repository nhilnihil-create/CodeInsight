#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n, q;
  string s;
  cin
    >> n >> q
    >> s;
  vector<int> l(q);
  vector<int> r(q);
  vector<int> sum(n + 1);
  for (int i = 0; i < q; i++) {
    cin >> l[i] >> r[i];
  }

  sum[0] = 0;
  sum[1] = 0;
  for (int i = 1; i < n; i++) {
    if (s[i - 1] == 'A' && s[i] == 'C') {
      sum[i + 1] = sum[i] + 1;
    } else {
      sum[i + 1] = sum[i];
    }
  }

  for (int i = 0; i < q; i++) {
    int result = sum[r[i]] - sum[l[i]];
    cout << result << endl;
  }

  return 0;
}