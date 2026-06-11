#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }

  if (cnt[0] > 0 || cnt[12] > 1) {
    cout << 0 << endl;
    exit(0);
  }

  for (auto&& w : cnt) {
    if (w.second >= 3) {
      cout << 0 << endl;
      exit(0);
    }
  }

  int ans = 0;
  for (int bit = 0; bit < 1 << 11; bit++) {
    vector<int> v;
    v.push_back(0);
    for (int i = 0; i < 11; i++) {
      if (cnt[i + 1] == 1) {
        if ((bit >> i & 1) == 0)
          v.push_back(i + 1);
        else
          v.push_back(24 - i - 1);
      } else if (cnt[i + 1] == 2) {
        v.push_back(i + 1);
        v.push_back(24 - i - 1);
      }
    }
    if (cnt[12] == 1) v.push_back(12);
    sort(begin(v), end(v));
    int tmp = 24 - v.back();
    for (int i = 0; i < v.size() - 1; i++) {
      tmp = min(tmp, v[i + 1] - v[i]);
    }
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}