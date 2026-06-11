#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;

ll lcm(int x, int y)
{
  return 1ll * x / __gcd(x, y) * y;
}

signed main(void)
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  if (fopen("A.INP", "r")){
    freopen("A.INP", "r", stdin);
    freopen("A.OUT", "w", stdout);
  }
  int n, m;
  string s, t;
  cin >> n >> m >> s >> t;
  ll L = lcm(n, m);
  int x = L / n, y = L / m, z = __gcd(n, m);
  for (int i = 0; i < z; ++i){
    if (s[i * y] != t[i * x]){
      cout << -1;
      return 0;
    }
  }
  cout << L;
}
