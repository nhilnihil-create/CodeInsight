#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, k;
  string s;
  cin >> n >> k >> s;

  vector<pair<char, int>> comp_s{{s.front(), 1}};
  for (int i = 1; i < s.size(); ++i) {
    auto &last_p = comp_s.back();
    if (last_p.first == s[i]) {
      last_p.second++;
    } else {
      comp_s.push_back({s[i], 1});
    }
  }

  vector<int> z_indeces;
  for (int i = 0; i < comp_s.size(); ++i) {
    if (comp_s[i].first == '0') {
      z_indeces.push_back(i);
    }
  }

  if (z_indeces.size() <= k) {
    cout << s.size() << '\n';
    return 0;
  }

  vector<int> csum{0};
  for (int i = 0; i < z_indeces.size(); i++) {
    int idx = z_indeces[i];
    int cnt = comp_s[idx].second;
    if (idx + 1 < comp_s.size()) {
      cnt += comp_s[idx + 1].second;
    }

    csum.push_back(csum.back() + cnt);
  }

  int ans = 0;
  for (int i = 0; i < csum.size() - k; ++i) {
    int cnt = csum[i + k] - csum[i];
    if (z_indeces[i] > 0) {
      int idx = z_indeces[i] - 1;
      cnt += comp_s[idx].second;
    }

    ans = max(ans, cnt);
  }

  cout << ans << '\n';
}