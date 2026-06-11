#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <bitset>
#include <set>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);i++)
#define all(i,n) (i),(i+n)

int dx4[4]={1,0,-1,0};
int dy4[4]={0,-1,0,1};
int dx8[8]={1,0,-1,1,-1,1,0,-1};
int dy8[8]={1,1,1,0,0,-1,-1,-1};

typedef pair<int, int> P;
typedef pair<string, int> SP;
typedef long long ll;
typedef pair<ll, ll> PLL;

const int INF = 1e9;
const ll LLINF = 1e18;
const int MAX_V = 1e6+1;
const ll mod = 1000000007;

// --------------------------------------
int n, k;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n >> k;
  vector<ll> x(n);
  vector<ll> x_cp(n);
  vector<ll> y(n);
  vector<ll> y_cp(n);

  REP(i, n) {
    cin >> x[i] >> y[i];
    x_cp[i] = x[i];
    y_cp[i] = y[i];
  }

  sort(x.begin(), x.end());
  sort(y.begin(), y.end());

  ll ans = 1e19*2;
  REP(xi, n) {
    FOR(xj, xi + 1, n) {
      REP(yi, n) {
        FOR(yj, yi + 1, n) {
          ll sx = x[xi];
          ll tx = x[xj];
          ll sy = y[yi];
          ll ty = y[yj];
          int count = 0;
          REP(m, n) {
            ll nx = x_cp[m];
            ll ny = y_cp[m];
            if((sx <= nx && nx <= tx) && sy <= ny && (ny <= ty)) count++;
          }
          if(count >= k) ans = min(ans, (tx - sx) * (ty - sy));
        }
      }
    }
  }

  cout << ans << endl;
}
