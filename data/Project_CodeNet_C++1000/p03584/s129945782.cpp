#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<map>
#include<functional>
#include<set>
#include<numeric>

#pragma region
using namespace std;
#define FOR(i,r,n) for(ll i = (ll)(r); i < (ll)(n); i++)
#define rep(i,n) FOR(i,0LL,n)
#define RFOR(i,r,n) for(ll i=(ll)(n-1);i>=r;i--)
#define rrep(i,n) RFOR(i,0LL,n)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define COUNT(a,y,x) upper_bound(all(a), y) - lower_bound(all(a), x)
#define UNIQUE(a) sort(all(a)); a.erase(unique(all(a)), a.end())
#define SUM(a) accumulate(all(a),0LL)
#define pb push_back
#define endl '\n'
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef map<ll, ll> MAP;
const ll inf = 2222222222222222222LL;
const ll mod = 1000000007LL;

ll n = 0, m = 0, ans = 0, cnt = 0, tmp = 0, ma = -inf, mi = inf;
string s;
bool ok = true, flag = false;
ll dx[5] = { 1,-1,0,0,0 }, dy[5] = { 0,0,1,-1,0 };
ll ddx[9] = { 1,-1,0,0,1,1,-1,-1,0 }, ddy[9] = { 0,0,1,-1,1,-1,1,-1,0 };
#pragma endregion
#define MAX 222222

ll a[MAX], b[MAX];


int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  rep(i, n) cin >> a[i] >> b[i];
  rep(i, n) {
	ok = true;
	rep(bit, 30) if ((a[i] >> bit & 1) && !(m >> bit & 1)) ok = false;
	if (ok) ans += b[i];
  }
  rep(bit, 30) {
	if (!(m >> bit & 1)) continue;
	tmp = 0;
	rep(i, n) {
	  ok = true;
	  if (a[i] >> bit & 1) ok = false;
	  RFOR(k,bit+1,31) if ((a[i] >> k & 1) && !(m >> k & 1)) ok = false;
	  if (ok) tmp += b[i];
	}
	ans = max(ans, tmp);
  }


  cout << ans << endl;


  return 0;
}
