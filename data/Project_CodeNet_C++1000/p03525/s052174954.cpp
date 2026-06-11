#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  map<int, int> cnts;
  vector<int> vd{0};
  for (int i = 0; i < n; ++i) {
    int d;
    cin >> d;
    cnts[d]++;
    vd.push_back(d);
  }

  cnts[0]++;

  int mx = 0;
  for (auto p : cnts) {
    mx = max(mx, p.second);
  }

  if (mx >= 3 || cnts[0] >= 2 || cnts[12] >= 2) {
    cout << 0 << '\n';
    return 0;
  }

  auto solve = [&](int bit) {
    vector<int> vd2;
    if (cnts[0] > 0) {
      vd2.push_back(0);
    }

    if (cnts[12] > 0) {
      vd2.push_back(12);
    }

    for (int i = 1; i <= 11; ++i) {
      if (cnts[i] <= 0) {
        continue;
      }

      if (cnts[i] >= 2) {
        vd2.push_back(i);
        vd2.push_back(24 - i);
        continue;
      }

      if (bit & (1 << i)) {
        vd2.push_back(24 - i);
      } else {
        vd2.push_back(i);
      }
    }

    int ans = 24;
    for (int i = 0; i < vd2.size() - 1; ++i) {
      for (int j = i + 1; j < vd2.size(); ++j) {
        int diff = abs(vd2[i] - vd2[j]);
        ans = min(ans, min(diff, 24 - diff));
      }
    }

    return ans;
  };

  int ans = 0;
  for (int i = 0; i < (1 << 12); ++i) {
    ans = max(ans, solve(i));
  }

  cout << ans << '\n';
  return 0;
}