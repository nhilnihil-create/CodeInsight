#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  int n;
  cin >> n;
  map<int, int> mp;
  rep(i, n) {
    int tmp;
    cin >> tmp;
    mp[tmp]++;
  }
  int ans = 0;
  for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
    int key = itr->first, value = itr->second;
    if (key > value) ans += value;
    if (key < value) ans += (value - key);
  }
  cout << ans << endl;
  return 0;
}