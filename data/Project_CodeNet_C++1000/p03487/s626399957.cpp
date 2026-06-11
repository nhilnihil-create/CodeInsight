#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    mp[a]++;
  }

  ll cnt = 0;
  for (auto mpp : mp) {
    int x, y;
    x = mpp.first;
    y = mpp.second;
    if (x > y) {
      cnt += y;
    } else {
      cnt += y - x;
    }
  }

  cout << cnt << endl;
  return 0;
}
