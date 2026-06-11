#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

int main() {
  ll h, w; cin >> h >> w;
  ll n, m; cin >> n >> m;
  ll res = h*w;
  res -= n*w + m*h;
  res += n*m;
  cout << res << endl;
}