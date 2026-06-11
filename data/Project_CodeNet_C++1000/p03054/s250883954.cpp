#include <bits/stdc++.h>

using namespace std;
using P = pair<long, long>;

typedef long long int ll;

#define EPS (1e-7)
#define INF (1e18)
#define PI (acos(-1))

#define sortv(xs) sort(xs.begin(), xs.end())
#define sortvinv(xs) sort(xs.begin(), xs.end(), greater<long>())
#define lbv(xs, x) lower_bound(xs.begin(), xs.end(), x) - xs.begin()
#define ubv(xs, x) upper_bound(xs.begin(), xs.end(), x) - xs.begin()
#define bs(xs, x) binary_search(xs.begin(), xs.end(), x)
#define index_of(as, x) \
  distance(as.begin(), lower_bound(as.begin(), as.end(), x))
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define concat(xs, ys) (xs).insert((xs).end(), (ys).begin(), (ys).end())

long sd[4][200005];
long td[4][200005];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  long h, w, n;
  cin >> h >> w >> n;

  long x, y;
  cin >> y >> x;

  bool res = true;
  string s,t;
  cin >> s >> t;
  {
    long ud = w;
    long ld = 1;
    per(i, n) {
      if (i != n-1) {
        if (t[i] == 'R') {
          ld = max(1L, ld-1);
        }
        if (t[i] == 'L') {
          ud = min(w, ud+1);
        }
      }
      if (s[i] == 'L') {
        ld++;
      }  
      if (s[i] == 'R') {
        ud--;
      }
      if (ud < ld) {
        res = false;
        break;
      }
    }
    if (x < ld || x > ud) {
      res = false;
    }
  }
  {
    long ud = h;
    long ld = 1;
    per(i, n) {
      if (i != n-1) {
        if (t[i] == 'D') {
          ld = max(1L, ld-1);
        }
        if (t[i] == 'U') {
          ud = min(h, ud+1);
        }
      }
      if (s[i] == 'U') {
        ld++;
      }  
      if (s[i] == 'D') {
        ud--;
      }
      if (ud < ld) {
        res = false;
        break;
      }
    }
    if (y < ld || y > ud) {
      res = false;
    }
  }


  cout << (res?"YES":"NO") << endl;
}
