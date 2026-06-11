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

static const long long MOD = 1000000007;
static const long long LINF = (long long)(1e18+99);
static const int INF = 1000000099;

ll n, a[10005], b[10005];
int main(void) {
  cin >> n;
  
  ll suma = 0, sumb = 0;
  rep(i, 0, n) {cin >> a[i]; suma += a[i];}
  rep(i, 0, n) {cin >> b[i]; sumb += b[i];}
  
  ll t = sumb - suma;
  
  if (t<0) {
    puts("No");
    return 0;
  }
  
  ll ax = 0, bx = 0;
  rep (i, 0, n) {
    ll d = b[i] - a[i];
    if (d<0) {
      bx += d*-1;
    } else {
      if (d%2!=0) {
        ax += d + 1;
        bx++;
      } else {
        ax += d;
      }
      
    }
    //printf("ax %lld, bx %lld\n", ax, bx);
  }
  
  ll at = t*2 - ax;
  ll bt = t - bx;
  
  if (at>=0 && bt>=0 && at==bt) puts("Yes");
  else puts("No");
  
    //cout << ans << endl;
    return 0;
}
