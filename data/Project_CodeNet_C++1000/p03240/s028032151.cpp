#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reps(i,a,b) for(int i= a; i < b; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int n;
  cin >> n;
  vector<int> xs(n);
  vector<int> ys(n);
  vector<ll> hs(n);
  rep(i, n) cin >> xs[i] >> ys[i] >> hs[i];
  rep(i, 101)rep(j, 101) {
    ll ch = -1;
    bool ok = true;
    rep(k, n) {
      if (hs[k] != 0) {
        ll tmp = hs[k] + abs(xs[k] - i) + abs(ys[k] - j);
        if (ch == -1) {
          ch = tmp;
        } else {
          if (ch != tmp) {
            ok = false;
            break;
          }
        }        
      }
    }
    if (!ok) continue;
  
    rep(k, n) {
      if (hs[k] == 0) {
        ll tmp = abs(xs[k] - i) + abs(ys[k] - j);
        if (ch > tmp) {
          ok = false;
          break;
        }
      }
    }

    if (ok) {
      cout << i << " " << j << " " << ch << endl;
    }

  }
  
  return 0;
}