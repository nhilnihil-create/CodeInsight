#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  ll n;
  cin >> n;
  vector<ll> b(n);
  rep(i, n) cin >> b[i];

  vector<ll> ans;
  while (b.size()) {
    bool ok = false;
    for (int i = b.size() - 1; i >= 0; --i) {
      if (b[i] == i + 1) {
        ans.push_back(b[i]);
        b.erase(b.begin() + i);
        ok = true;
        break;
      }
    }
    if (!ok) {
      puts("-1");
      return 0;
    }
  }

  for (int i = n - 1; i >= 0; --i) cout << ans[i] << endl;
  return 0;
}
