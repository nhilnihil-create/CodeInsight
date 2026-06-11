#include <bits/stdc++.h>

#define mk make_pair
#define sc second
#define fr first
#define pb emplace_back
#define all(s) s.begin(), s.end()
#define sz(s) ( (int)s.size() )
#define int long long

using namespace std;

const int inf = (int)1e9 + 7;
const int N = (int)2e6 + 7;

int n,c;
int x[N],y[N];
int d1[N],d2[N];
int mx1[N],mx2[N];
int ans;

main () {
      cin >> n >> c;

      for (int i = 1; i <= n; i ++) {
            cin >> x[i] >> y[i];
      }

      for (int i = 1; i <= n; i ++) {
            d1[i] = d1[i - 1] - (x[i] - x[i - 1]) + y[i];
            mx1[i] = max(mx1[i - 1],d1[i] - x[i]);
      }
      x[n + 1] = c;
      y[n + 1] = 0;
      d2[n + 1] = 0;
      mx2[n + 1] = 0;

      for (int i = n; i >= 1; i --) {
            d2[i] = d2[i + 1] - (x[i + 1] - x[i]) + y[i];
            mx2[i] = max(mx2[i + 1],d2[i] - (c - x[i]));
      }
      for (int i = 0; i <= n; i ++) {
            ans = max(ans,d1[i] + mx2[i + 1]);
            ans = max(ans,mx1[i] + d2[i + 1]);
      }
      cout << ans << endl;
}
