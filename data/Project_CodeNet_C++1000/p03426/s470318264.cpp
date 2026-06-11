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

const int INF = 1e9;
const ll LLINF = 1e18;
const int MAX_V = 1e6+1;
const ll mod = 1000000007;

// --------------------------------------
int h, w, d, q;
struct grid_pos { int x, y; };
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> h >> w >> d;

  vector<grid_pos> vg(h * w + 1);

  FOR(i, 1, h + 1) FOR(j, 1, w + 1) {
    int a;
    cin >> a;
    grid_pos gp = {i, j};
    vg[a] = gp;
  }

  vector<int> memo(h * w + 1, 0);
  for(int i=h*w; (h*w-d)<i; i--) {
    grid_pos gp = vg[i];
    int sum = 0;
    for(int j=d; (i-j)>0; j+=d) {
      grid_pos n_gp = vg[i - j];
      sum += abs(gp.x - n_gp.x) + abs(gp.y - n_gp.y);
      memo[i - j] = sum;
      gp = n_gp;
    }
  }

  cin >> q;
  REP(i, q) {
    int l, r;
    cin >> l >> r;
    cout << memo[l] - memo[r] << endl;
  }
}
