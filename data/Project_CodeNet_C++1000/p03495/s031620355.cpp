#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, k;
  cin >> n >> k;

  vector<int> va(n);
  map<int, int> cnts;
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
    cnts[va[i]]++;
  }

  vector<int> vc;
  for (auto &p : cnts) {
    vc.push_back(p.second);
  }

  sort(vc.begin(), vc.end());
  int kk = max(0, static_cast<int>(vc.size()) - k);
  int ans = 0;
  for (int i = 0; i < kk; i++) {
    ans += vc[i];
  }

  cout << ans << '\n';
}
