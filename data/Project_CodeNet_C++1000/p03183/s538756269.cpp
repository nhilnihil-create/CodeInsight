#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

void self_max(ll &a, ll b) {
	a = max(a,b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	vl w(n), s(n), v(n);
	FOR(i,0,n) cin >> w[i] >> s[i] >> v[i];

	vl is(n);
	iota(all(is),0);
	sort(all(is),[&](ll i, ll j) {
		return s[i]+w[i] < s[j]+w[j];
	});
	
	ll W = 20005;

	vl dp(W,-1);
	dp[0] = 0;
	for (ll i: is) {
		FORD(j,0,s[i]+1) if (dp[j] != -1) {
			self_max(dp[j+w[i]], dp[j] + v[i]);
		}
	}
	cout << *max_element(all(dp)) << endl;
}

