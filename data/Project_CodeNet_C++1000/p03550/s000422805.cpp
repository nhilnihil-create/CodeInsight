#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()

using namespace std;

typedef long long ll;
typedef long double ld;

using P = pair<ll, ll>;

static const long long MOD = 1000000007;
static const long long LINF = (ll)(1e18+99);
static const int INF = 1e9+99;

int n, z, w, a[2005], X[2005], Y[2005];

int main(void) {
  cin >> n >> z >> w;
  rep(i, 0, n) scanf("%d", &a[i]);
  
  for (int i=n-2; i>=0; i--) {
    int ymin, xmax;
    ymin = xmax = abs(a[i]-a[n-1]);
    for (int j=i+1; j<n-1; j++) {
      ymin = min(ymin, Y[j]);
      xmax = max(xmax, X[j]);
    }
    X[i] = ymin;
    Y[i] = xmax;
  }
  
  int ans = abs(w-a[n-1]);
  rep(i, 0, n-1) ans = max(X[i], ans);
  
    cout << ans << "\n";

    return 0;
}

