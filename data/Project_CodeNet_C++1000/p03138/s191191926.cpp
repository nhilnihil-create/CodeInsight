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
ll n, k;
ll dp[64][2];
int bit_count(ll t) {
  int c = 0;
  while(t) {
    t /= 2;
    c++;
  }
  return c;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n >> k;

  int ma = bit_count(k);
  vector<ll> a(n);
  REP(i, n) {
    cin >> a[i];
    ma = max(bit_count(a[i]), ma);
  }

  vector<ll> bs(ma, 0);
  REP(i, n) {
    int c = 1;
    ll t = a[i];
    while(t) {
      if(t % 2) bs[ma - c]++;
      c++;
      t /= 2;
    }
  }

  bool under = false;
  REP(i, ma) {
    if(1LL << (ma - (i + 1)) > k) {
      dp[i + 1][0] = dp[i][0] + bs[i] * (1LL << (ma - (i + 1)));
    } else {
      if(under) {
        dp[i + 1][1] = dp[i][1] + max(bs[i], n - bs[i]) * (1LL << (ma - (i + 1)));
      }
      if(1LL << (ma - (i + 1)) & k) {
        dp[i + 1][0] = max(dp[i + 1][0], dp[i][0] + (n - bs[i]) * (1LL << (ma - (i + 1))));
        dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] + bs[i] * (1LL << (ma - (i + 1))));
        under = true;
      } else {
        dp[i + 1][0] = max(dp[i + 1][0], dp[i][0] + bs[i] * (1LL << (ma - (i + 1))));
      }
    }
  }

  cout << max(dp[ma][0], dp[ma][1]) << endl;
}
