#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<int> wCount(n);
  wCount[0] = 0;
  for (int i = 1; i < n; ++i) {
    wCount[i] = wCount[i - 1];
    if (s[i - 1] == 'W') {
      wCount[i] += 1;
    }
  }
  vector<int> eCount(n);
  eCount[n - 1] = 0;
  for (int i = n - 2; i >= 0; --i) {
    eCount[i] = eCount[i + 1];
    if (s[i + 1] == 'E') {
      eCount[i] += 1;
    }
  }

  int res = n;
  for (int i = 0; i < n; ++i) {
    res = min(res, wCount[i] + eCount[i]);
  }
  cout << res << endl;
}
