#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
int main() {
  cin >> n >> m;
  pair<ll,ll> p[n];
  for (int i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
  }
  sort(p,p+n);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (p[i].second > m) {
      ans += m * p[i].first;
      break;
    } else {
      ans += p[i].second * p[i].first;
      m -= p[i].second;
    }
  }
  cout << ans << endl;
}

/*　【提出前に確認すること】
・コンパイルできるか
・テストケース試したか
・オーバーフローあるか
*/
