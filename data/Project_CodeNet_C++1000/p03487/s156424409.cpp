#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
int main() {
  int n;
  cin >> n;
  map<int, int> s;

  ll ans = 0;

  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;

    s[temp]++;
  }

  for (auto it = s.begin(); it != s.end(); it++) {
    if (it->first > it->second) {
      ans += it->second;
    } else {
      ans += (it->second - it->first);
    }
  }

  cout << ans << endl;
}