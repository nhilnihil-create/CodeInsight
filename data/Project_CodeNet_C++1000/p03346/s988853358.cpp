#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }

  vector<int> pos(n + 1, -1);
  for (int i = 0; i < n; ++i) {
    pos[p[i] - 1] = i;
  }

  int cnt = 0;
  int q = 0;
  for (int i = 1; i < pos.size(); ++i) {
    if (pos[i - 1] > pos[i]) {
      cnt = max(cnt, i - q);
      q = i;
    }
  }

  cout << n - cnt << endl;
}