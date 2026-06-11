#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<int> va(n);
  map<int, int> cnt1, cnt2;
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
    if (i % 2 == 0) {
      cnt1[va[i]]++;
    } else {
      cnt2[va[i]]++;
    }
  }

  int max1 = 0, max2 = 0, max3 = 0, max4 = 0;
  for (auto &p : cnt1) {
    if (cnt1[max1] < p.second) {
      int old = max1;
      max1 = p.first;
      max2 = old;
    } else if (cnt1[max2] < p.second) {
      max2 = p.first;
    }
  }

  for (auto &p : cnt2) {
    if (cnt2[max3] < p.second) {
      int old = max3;
      max3 = p.first;
      max4 = old;
    } else if (cnt2[max4] < p.second) {
      max4 = p.first;
    }
  }

  if (max1 != max3) {
    int ans = n - cnt1[max1] - cnt2[max3];
    cout << ans << '\n';
  } else {
    int ans = n - max(cnt1[max1] + cnt2[max4], cnt1[max2] + cnt2[max3]);
    cout << ans << '\n';
  }
}