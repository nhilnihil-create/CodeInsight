#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int minTime(vector<int> &arr) {
  int time = 24;
  vector<int> c;
  rep(i, arr.size()) if (arr[i] >= 1) c.push_back(i);

  rep(i, c.size() - 1) time = min(time, c[i + 1] - c[i]);
  time = min(time, 24 - c.back());
  return time;
}

int main() {
  int n;
  cin >> n;

  vector<int> d(n);
  rep(i, n) cin >> d[i];

  map<int, int> mp;
  rep(i, n) {
    if (d[i] >= 13) d[i] = 24 - d[i];
    mp[d[i]]++;
  }

  for (auto x : mp) {
    if ((x.first == 0 && x.second >= 1) || (x.first == 12 && x.second >= 2) ||
        (x.first != 0 && x.first != 12 && x.second >= 3)) {
      cout << 0 << endl;
      return 0;
    }
  }

  int ans = 0;
  for (int i = 0; i < (1 << 11); i++) {
    vector<int> time(24, 0);
    time[0] = 1;
    if (mp.count(12)) time[12] = 1;
    bool good = true;
    rep(j, 11) {
      if (i & (1 << j)) {
        if (mp[(j + 1)] == 2) time[(j + 1)] = 1, time[(24 - (j + 1))] = 1;
        if (mp[(j + 1)] == 1) time[(j + 1)] = 1;
      } else {
        if (mp[(j + 1)] == 2) good = false;
        if (mp[(j + 1)] == 1) time[24 - (j + 1)] = 1;
      }
    }
    
    if (!good) continue;
    int t = minTime(time);
    ans = max(ans, t);
  }

  cout << ans << endl;
}
