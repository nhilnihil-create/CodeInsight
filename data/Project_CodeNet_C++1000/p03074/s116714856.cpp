#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n, k;
  string s;
  cin >> n >> k >> s;
  
  vector<int> x;
  int count = 1;
  for (int i = 1; i < n; i++) {
    if (s.at(i - 1) == s.at(i)) count++;
    else {
      x.emplace_back(count);
      count = 1;
    }
  }
  x.emplace_back(count);
  
  int ans = 0;
  if (s.at(0) == '0') {
    if ((x.size() + 1) / 2 <= k) {
      cout << n << '\n';
      return 0;
    }
    int ans = 0;
    int left = 0, count = 0, sum = 0;
    for (int right = 0; right < x.size(); right++) {
      sum += x.at(right);
      if (right % 2 == 0) count++;
      if (count > k) {
        if (left == 0) {
          sum -= x.at(left);
          left++;
          count--;
        }
        else {
          sum -= x.at(left) + x.at(left + 1);
          left += 2;
          count--;
        }
      }
      ans = max(ans, sum);
    }
    cout << ans << '\n';
  }
  else {
    if (x.size() / 2 <= k) {
      cout << n << '\n';
      return 0;
    }
    int ans = 0;
    int left = 0, count = 0, sum = 0;
    for (int right = 0; right < x.size(); right++) {
      sum += x.at(right);
      if (right % 2 == 1) count++;
      if (count > k) {
        sum -= x.at(left) + x.at(left + 1);
        left += 2;
        count--;
      }
      ans = max(ans, sum);
    }
    cout << ans << '\n';
  }
}