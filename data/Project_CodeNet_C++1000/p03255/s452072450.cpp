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


ll sum[MAX];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll x;
  cin >> n >> x;
  vll a(n);
  rep(i, n) cin >> a[i];
  sort(rall(a));
  ans = n * x;
  FOR(i, 1, n + 1) sum[i] += sum[i - 1] + a[i - 1];
  FOR(i, 1, n + 1) {
	tmp = 5 * sum[i];
	cnt = (n + i - 1) / i;
	FOR(j, 2, cnt + 1) {
	  tmp += (sum[min(i*j, n)] - sum[i*(j - 1)])*(2 * j + 1);
	  if (tmp < 0) break;
	}
	tmp += x * i;
	if (tmp > 0) mi = min(mi, tmp);
  }

  cout << ans + mi << endl;


  return 0;
}