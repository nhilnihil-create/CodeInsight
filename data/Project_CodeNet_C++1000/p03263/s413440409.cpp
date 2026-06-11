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
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);i++)
#define all(i,n) (i),(i+n)

int dx4[4]={1,0,-1,0};
int dy4[4]={0,-1,0,1};
int dx8[8]={1,0,-1,1,-1,1,0,-1};
int dy8[8]={1,1,1,0,0,-1,-1,-1};
int dx9[9]={0,1,0,-1,1,-1,1,0,-1};
int dy9[9]={0,1,1,1,0,0,-1,-1,-1};

typedef pair<int, int> P;
typedef pair<string, int> SP;
typedef long long ll;
typedef pair<ll, ll> PLL;

const int INF = 1e9;
const ll LLINF = 1e18;
const int MAX_V = 1e6+1;
const ll mod = 1000000007;
// << fixed << setprecision
// --------------------------------------
int h, w;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> h >> w;

  int a[501][501];

  REP(i, h) REP(j, w) cin >> a[i][j];
  vector<int> ans;

  auto gp = [](int t) {
    int y = t / w;
    int x = (y % 2 == 0 ? t % w : w - (t % w + 1));
    return P(y, x);
  };

  REP(i, h * w - 1) {
    P yx = gp(i);
    P nyx = gp(i + 1);

    if(a[yx.first][yx.second] % 2) {
      a[yx.first][yx.second]--;
      a[nyx.first][nyx.second]++;
      ans.push_back(i);
    }
  }

  cout << ans.size() << endl;

  REP(i, ans.size()) {
    P p = gp(ans[i]);
    P np = gp(ans[i] + 1);
    cout << p.first + 1 << " " << p.second + 1 << " " << np.first + 1 << " " << np.second + 1 << endl;
  }
}
