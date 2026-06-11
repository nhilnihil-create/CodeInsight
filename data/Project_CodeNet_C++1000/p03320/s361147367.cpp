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

#pragma region
using namespace std;
#define FOR(i,r,n) for(ll i = (ll)(r); i < (ll)(n); i++)
#define rep(i,n) FOR(i,0,n)
#define RFOR(i,r,n) for(ll i=(ll)(n-1);i>=r;i--)
#define rrep(i,n) RFOR(i,0,n)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define lower(a,x) lower_bound(all(a), x) - a.begin();
#define COUNT(a,x)  upper_bound(all(a), x) - lower_bound(all(a), x);
#define MCOUNT(a,x,y) upper_bound(all(a), y) - lower_bound(all(a), x);
#define UNIQUE(a) sort(all(a)); a.erase(unique(all(a)), a.end());
#define scan(x) scanf("%lld",&x);
#define pb push_back
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef map<ll, ll> MAP;
typedef set<ll> SET;
typedef double D;
const ll inf = 5555555555555555555;
const ll mod = 1000000007;
const D pi = acos(-1);
const D eps = 1e-10;

ll n = 0, m = 0, ans = 0, sum = 0, cnt = 0, tmp = 0, ma = -inf, mi = inf;
string s;
bool ok, flag;
ll dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
ll ddx[9] = { 1,-1,0,0,1,1,-1,-1,0 }, ddy[9] = { 0,0,1,-1,1,-1,1,-1,0 };
#pragma endregion
#define MAX 111111

ll digit_sum(ll x) {
  ll ret = 0;
  string y = to_string(x);
  rep(i, y.length()) ret += y[i] - '0';
  return ret;
}
string ss[18];
double mm[MAX*2];
int main(void) {
  ll k;
  vll a;
  cin >> k;

  FOR(i, 1, 16) ss[i] = ss[i - 1] + "9";
  FOR(i, 1, 10000) {
	string s1 = to_string(i);
	FOR(j, 1, 16) {
	  string s2 = s1 + ss[j];
	  if (s2.length() > 15)continue;
	  tmp = stoll(s2);
	  a.pb(tmp);
	}
  }
  FOR(i, 1, 10) a.pb(i);

  sort(all(a));
  UNIQUE(a);
  m = a.size();
  mm[m] = inf;
  rrep(i, m) mm[i] = min(mm[i + 1], (double)a[i] / digit_sum(a[i]));
  while (k) {
	if ((double)a[cnt] / digit_sum(a[cnt]) <= mm[cnt + 1]) {
	  cout << a[cnt] << endl;
	  k--;
	}
	cnt++;
  }

  return 0;
}