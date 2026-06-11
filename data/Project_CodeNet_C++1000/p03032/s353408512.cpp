#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  rep(i, n)
    cin >> v[i];
  int ans = 0;
  rep(l, min(n + 1, k + 1))
    rep(r, min(n + 1, k + 1) - l)
      rep(d, k + 1 - l - r)
      {
        vector<int> g(l + r);
        rep(i, l)
          g.push_back(v[i]);
        rep(i, r)
          g.push_back(v[n-1-i]);
        sort(g.begin(), g.end());
        int total = 0;
        rep(i, g.size())
          if (i >= d || g[i] > 0)
            total += g[i];
        ans = max(ans, total);
      }
  cout << ans << endl;
  return 0;
}