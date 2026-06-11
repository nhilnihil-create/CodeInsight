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
int a, b, q;

PLL nodes(vector<ll>& v, ll n) {
  auto it = upper_bound(v.begin(), v.end(), n);
  ll s, t;
  if(it == v.end()) {
    s = *(it - 1);
    t = -1;
  } else if(it == v.begin()) {
    t = *it;
    s = -1;
  } else {
    t = *it;
    s = *(it - 1);
  }

  return PLL(s, t);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> a >> b >> q;

  vector<ll> s(a);
  vector<ll> t(b);

  REP(i, a) cin >> s[i];
  REP(i, b) cin >> t[i];

  REP(i, q) {
    ll n;
    cin >> n;

    PLL s_n = nodes(s, n);
    PLL t_n = nodes(t, n);

    ll ans = LLINF;

    if(s_n.first != -1 && t_n.first != -1) {
      ans = min(ans, max(n - s_n.first, n - t_n.first));
    }
    if(s_n.first != -1 && t_n.second != -1) {
      ll t = min(n - s_n.first, t_n.second - n) * 2 + max(n - s_n.first, t_n.second - n);
      ans = min(ans, t);
    }
    if(s_n.second != -1 && t_n.first != -1) {
      ll t = min(s_n.second - n, n - t_n.first) * 2 + max(s_n.second - n, n - t_n.first);
      ans = min(ans, t);
    }
    if(s_n.second != -1 && t_n.second != -1) {
      ans = min(ans, max(s_n.second - n, t_n.second - n));
    }
    cout << ans << endl;
  }
}
