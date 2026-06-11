#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<int> d(n), e(13);
  for (int i = 0; i < n; i++) {
    cin >> d.at(i);
    e.at(d.at(i))++;
  }
  
  vector<int> x;
  x.emplace_back(0);
  x.emplace_back(24);
  
  bool flag = true;
  for (int i = 0; i < 13; i++) {
    if (i == 0 && e.at(i) > 0) {
      cout << "0\n";
      return 0;
    }
    else if (i == 12) {
      if (e.at(i) > 1) {
        cout << "0\n";
        return 0;
      }
      if (e.at(i) == 1) x.emplace_back(i);
    }
    else {
      if (e.at(i) > 2) {
        cout << "0\n";
        return 0;
      }
      if (e.at(i) == 2) {
        x.emplace_back(i);
        x.emplace_back(24 - i);
      }
      else if (e.at(i) == 1) {
        if (flag) x.emplace_back(i);
        else x.emplace_back(24 - i);
        flag ^= true;
      }
    }
  }
  
  sort(x.begin(), x.end());
  int ans = 24;
  for (int i = 1; i < x.size(); i++) ans = min(ans, x.at(i) - x.at(i - 1));
  cout << ans << '\n';
}