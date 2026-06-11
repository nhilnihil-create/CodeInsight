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
ll n, k;
ll a[100005];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n >> k;
  REP(i, n) cin >> a[i];

  ll dp[42][2];
  REP(i, 42) REP(j, 2) dp[i][j] = -LLINF;
  dp[40][0] = 0;

  RREP(i, 40) {
    ll D = 1LL << i;

    int num1 = 0;
    REP(j, n) if((a[j] >> i) & 1) num1++;
    int num0 = n - num1;

    if((k >> i) & 1) {
      dp[i][0] = max(dp[i][0], dp[i + 1][0] + D * num0);
      dp[i][1] = max(dp[i][1], dp[i + 1][0] + D * num1);
    } else {
      dp[i][0] = max(dp[i][0], dp[i + 1][0] + D * num1);
    }
    dp[i][1] = max(dp[i][1], dp[i + 1][1] + D * max(num0, num1));
  }

  cout << max(dp[0][0], dp[0][1]) << endl;
}
