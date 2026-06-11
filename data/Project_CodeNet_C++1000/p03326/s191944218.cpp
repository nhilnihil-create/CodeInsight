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
int n, m;
ll x[1005], y[1005], z[1005];

ll calc(ll a, int p) {
  if(p == 0) return a;
  else return -a;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  REP(i, n) cin >> x[i] >> y[i] >> z[i];

  ll ans = -LLINF;
  REP(i, 2) REP(j, 2) REP(k, 2) {
    vector<ll> v;
    REP(l, n) {
      ll sum = 0;
      sum += calc(x[l], i);
      sum += calc(y[l], j);
      sum += calc(z[l], k);
      v.push_back(sum);
    }

    sort(v.begin(), v.end(), greater<ll>());
    ll tmp = 0;
    REP(l, m) tmp += v[l];
    ans = max(ans, tmp);
  }

  cout << ans << endl;
}
