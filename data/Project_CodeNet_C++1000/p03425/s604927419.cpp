#include <bits/stdc++.h>
//#include "atcoder/all"
using namespace std;
typedef long long ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
const ll mod = 1e9 + 7;
int main() {
  int n;
  cin >> n;
  map<char, ll> m;
  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;
    m[temp[0]]++;
  }

  vector<ll> num{m['M'], m['A'], m['R'], m['C'], m['H']};
  ll ans = 0;

  for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j < 5; j++) {
      for (int k = j + 1; k < 5; k++) {
        ans += num[i] * num[j] * num[k];
      }
    }
  }
  cout << ans << endl;
}