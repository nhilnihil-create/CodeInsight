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
int n, C;
int d[30][30];
int c[501][501];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n >> C;
  REP(i, C) REP(j, C) cin >> d[i][j];

  REP(i, n) REP(j, n) {
    cin >> c[i][j];
    c[i][j]--;
  }

  int c_0[30];
  int c_1[30];
  int c_2[30];

  REP(i, C) {
    ll sum_0 = 0;
    ll sum_1 = 0;
    ll sum_2 = 0;
    REP(l, n) REP(p, n) {
      if((l + p) % 3 == 0) sum_0 += d[c[l][p]][i];
      else if((l + p) % 3 == 1) sum_1 += d[c[l][p]][i];
      else sum_2 += d[c[l][p]][i];
    }
    c_0[i] = sum_0;
    c_1[i] = sum_1;
    c_2[i] = sum_2;
  }

  ll ans = LLINF;
  REP(i, C) REP(j, C) REP(k, C) if(i != j && j != k && k != i) {
    ll sum = c_0[i] + c_1[j] + c_2[k];
    ans = min(ans, sum);
  }

  cout << ans << endl;
}
