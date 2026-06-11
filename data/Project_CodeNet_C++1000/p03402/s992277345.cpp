#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

#define REP(i,n) for(ll (i) = (0); (i) < (n); ++i)
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define ALL(v) v.begin(),v.end()
#define Decimal fixed << setprecision(20)
#define SHOWP(x) cerr<<"["<<(x).FI<<", "<<(x).SE<<"]";
#define SHOWX(x) cerr<<#x<<": "<<x<<endl;
#define SHOWVEC(v, e) REP(i, e) cerr << (v[i]) << ' '; cerr << endl;
#define SHOW2D(a, h, w) REP(i, h){REP(j, w)cerr<<setw(3)<<(a[i][j])<<' ';cerr<<endl;}
constexpr int INF = 1 << 30 - 1;
constexpr long long LLINF = 1LL << 60;
constexpr long long MOD = 1000000007;

typedef long long ll;
typedef pair<ll, ll> P;

char mp[100][100];
int main()
{
  int A, B;
  cin >> A >> B;
  REP(i, 100) {
    REP(j, 50) mp[i][j] = '.';
    REP(j, 50) mp[i][j + 50] = '#';
  }

  int y = 0, x = 0;
  REP(i, B - 1) {
    mp[y][x] = '#';
    x += 2;
    if (x >= 49) {
      x = 0;
      y += 2;
    }
  }

  y = 0, x = 51;
  REP(i, A - 1) {
    mp[y][x] = '.';
    x += 2;
    if (x >= 98) {
      x = 51;
      y += 2;
    }
  }

  cout << 100 << ' ' << 100 << endl;
  REP(i, 100) {
    REP(j, 100) cout << mp[i][j];
    cout << endl;
  }
  return 0;
}