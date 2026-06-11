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


ll x[1111], y[1111];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  
  cin >> n;
  rep(i, n) cin >> x[i] >> y[i];
  tmp = abs(x[0] + y[0]) % 2;
  rep(i, n) if (abs(x[i] + y[i]) % 2 != tmp) ok = false;
  if (!ok) {
	cout << "-1" << endl;
	return 0;
  }
  if (tmp == 0) {
	cout << "32" << endl;
	rrep(i, 31) cout << (1 << i) << " ";
	cout << "1 " << endl;
  }
  else {
	cout << "31" << endl;
	rrep(i, 31) cout << (1 << i) << " ";
	cout << endl;
  }

  rep(i, n) {
	ll a = x[i] + y[i], b = x[i] - y[i];
	rrep(j, 31) {
	  if (a >= 0 && b >= 0) {
		cout << "R"; a -= (1 << j); b -= (1 << j);
	  }
	  else if (a >= 0 && b < 0) {
		cout << "U"; a -= (1 << j); b += (1 << j);
	  }
	  else if (a < 0 && b >= 0) {
		cout << "D"; a += (1 << j); b -= (1 << j);
	  }
	  else {
		cout << "L"; a += (1 << j); b += (1 << j);
	  }
	}
	if (tmp == 0) {
	  if (a >= 0 && b >= 0) cout << "R";
	  else if (a >= 0 && b < 0) cout << "U";
	  else if (a < 0 && b >= 0) cout << "D";
	  else cout << "L";
	}
	cout << endl;
  }



  return 0;
}