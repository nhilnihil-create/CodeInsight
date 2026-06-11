#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n, k;
  cin >> n >> k;
  unordered_map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    mp[temp] += 1;
  }
  vector<int> num;
  for (auto x : mp) {
    num.push_back(x.second);
  }
  sort(num.begin(), num.end());
  int ans = 0;
  if (num.size() > k) {
    for (int i = 0; i < num.size() - k; i++) {
      ans += num[i];
    }
  }
  cout << ans << endl;
}