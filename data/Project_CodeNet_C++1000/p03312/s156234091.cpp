#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);
using ll = long long;
using ull = unsigned long long;
const int inf = 2e9;
const ll INF = 2e18;
const ll MOD = 1e9+7;
typedef pair<int,int> P;

#define REP(i,n) for (int i = 0; i < (n); i++)
#define sz(s) (s).size()
#define pb push_back
#define fi first
#define se second

int n;
ll a[200010];
int pl[200010], pr[200010];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  REP(i,n) cin >> a[i+1];
  REP(i,n) a[i+1] += a[i];

  int p = 1;
  for (int i = 2; i <= n-2; i++) {
    while (1) {
      if (abs(a[i] - a[p] - a[p]) > abs(a[i] - a[p+1] - a[p+1]) && p+1 < i) {
        p++;
      } else {
        pl[i] = p;
        break;
      }
    }
  }

  p = n;
  for (int i = n-2; i >= 2; i--) {
    while (1) {
      if (abs(a[n] - a[p] - (a[p] - a[i])) > abs(a[n] - a[p-1] - (a[p-1] - a[i])) && p-1 > i) {
        p--;
      } else {
        pr[i] = p;
        break;
      }
    }
  }

  //pl)i)pr)n)
  ll ans = INF;
  for (int i = 2; i <= n-2; i++) {
    ll aa,bb,cc,dd;
    aa = a[pl[i]];
    bb = a[i] - aa;
    cc = a[pr[i]] - a[i];
    dd = a[n] - aa - bb - cc;
    ans = min(ans, max({aa,bb,cc,dd}) - min({aa,bb,cc,dd}));
  }

  cout << ans << endl;
  return 0;
}
