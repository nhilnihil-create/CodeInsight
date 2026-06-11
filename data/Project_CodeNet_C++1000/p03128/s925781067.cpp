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

// --------------------------------------
int n, m;
int a[10];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int cost[10] { 0,2,5,5,4,5,6,3,7,6 };

  cin >> n >> m;
  REP(i, m) cin >> a[i];

  sort(a, a + m);

  int dp[12][10005];
  REP(i, m + 1) REP(j, n + 1) dp[i][j] = -1;
  REP(i, m + 1) dp[i][0] = 0;

  REP(i, m) {
    REP(j, n + 1) {
      if(j - cost[a[i]] >= 0 && dp[i + 1][j - cost[a[i]]] >= 0) {
        dp[i + 1][j] = max(dp[i + 1][j - cost[a[i]]] + 1, dp[i][j]);
      } else {
        dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
      }
    }
  }

  int d = dp[m][n];
  int y = m, x = n;

  while(d > 0) {
    if(x - cost[a[y - 1]] >= 0 && dp[y][x - cost[a[y - 1]]] == d - 1) {
      printf("%d", a[y - 1]);
      x = x - cost[a[y - 1]];
      d--;
    } else {
      y--;
    }
  }
}
