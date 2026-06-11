#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, a, b;
  cin >> n >> a >> b;

  vector<int> vp(n);
  for (int i = 0; i < n; ++i) {
    cin >> vp[i];
  }

  int cnt1, cnt2, cnt3;
  cnt1 = cnt2 = cnt3 = 0;
  for (int i = 0; i < n; ++i) {
    int p = vp[i];
    if (p <= a) {
      cnt1++;
    } else if (p <= b) {
      cnt2++;
    } else {
      cnt3++;
    }
  }

  cout << min({cnt1, cnt2, cnt3}) << '\n';
}