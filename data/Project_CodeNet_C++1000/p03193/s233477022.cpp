#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e9 + 7;

int main() {
  int n;
  ll h, w;
  cin >> n >> h >> w;

  int ans = 0;
  rep(i,n) {
    ll a, b;
    cin >> a>> b;
    if (a < h) continue;
    if (b < w) continue; 
    ans++;
  }
  cout << ans << endl;

  return 0;
}
