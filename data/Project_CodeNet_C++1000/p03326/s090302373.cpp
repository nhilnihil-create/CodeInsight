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
#include <deque>

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
typedef pair<ll, ll> PLL;

const int INF = 1e9;
const ll LLINF = 1e18;
const int MAX_V = 1e6+1;
const ll mod = 1000000007;

// --------------------------------------
int n, m;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  vector<ll> a(n);
  vector<ll> b(n);
  vector<ll> c(n);

  REP(i, n) cin >> a[i] >> b[i] >> c[i];

  auto f = [](ll x, ll y) {
    return (x ? y : -y);
  };

  ll ans = 0;
  REP(i, 1 << 3) {
    vector<ll> cal;
    REP(j, n) {
      ll t = f(i & (1 << 0), a[j]) + f(i & (1 << 1), b[j]) + f(i & (1 << 2), c[j]);
      cal.push_back(t);
    }
    sort(cal.begin(), cal.end(), greater<ll>());
    ll sum = 0;
    REP(j, m) sum += cal[j];
    ans = max(ans, sum);
  }

  cout << ans << endl;
}
