#include <bits/stdc++.h>
#include <unordered_map>

const double PI = acos(-1);

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
using P = pair<ll, ll>;
using V = vector<ll>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep1(i, n) for(ll i=1;i<=(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define MOD 1000000007
#define INF 1000000000

void solve_abc_c() {
	ll n, m;
	ll k;
	ll h, w;
	//ll x;
	//ll a;
	string s;
	string s_ans;
	ll l_ans = 0;
	double d_ans = 0;

	cin >> n;
	V a(5);
	ll idx = 0;
	ll val = 1e16;
	rep(i, 5) {
		cin >> a[i];
		val = min(val, a[i]);
	}

	l_ans += (n + val - 1) / val;
	l_ans += 4;

	cout << l_ans << "\n";
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed;
	cout << setprecision(15);

	solve_abc_c();

	return 0;
}
