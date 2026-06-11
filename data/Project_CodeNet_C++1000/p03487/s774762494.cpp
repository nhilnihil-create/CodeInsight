#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  unordered_map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    mp[x]++;
  }
  long long ans = 0;
  for (auto p : mp) {
    int sum = p.second - p.first;
    if (p.second < p.first) {
      sum = p.second;
    }
    ans += sum;
  }
  cout << ans;
}
