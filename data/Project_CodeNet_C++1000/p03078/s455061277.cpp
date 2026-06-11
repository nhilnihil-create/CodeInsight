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
int x, y, z, k;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> x >> y >> z >> k;
  vector<ll> a(x);
  vector<ll> b(y);
  vector<ll> c(z);

  REP(i, x) cin >> a[i];
  REP(i, y) cin >> b[i];
  REP(i, z) cin >> c[i];

  vector<ll> ab;
  REP(i, x) REP(j, y) {
    ab.push_back(a[i] + b[j]);
  }

  sort(ab.begin(), ab.end(), greater<ll>());

  vector<ll> ans;
  REP(i, min(x * y, k)) REP(j, z) {
    ans.push_back(ab[i] + c[j]);
  }

  sort(ans.begin(), ans.end(), greater<ll>());

  REP(i, k) cout << ans[i] << endl;
}
