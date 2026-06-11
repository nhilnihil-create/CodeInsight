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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, L, R;
	cin >> n >> L >> R;
	swap(L,R);

	vl p(n+2);
	FOR(i,1,n+1) cin >> p[i];
	p[n+1] = n+1;
	n += 2;

	vl dp(n);
	vl inv(n);

	FOR(i,1,n) {
		FOR(j,0,i) if (p[j] > p[i]) inv[j]++;
		
		dp[i] = oo;
		ll cntR = 0;
		FORD(j,0,i) {
			if (p[j] > p[i]) {
				cntR++;
			} else {
				ll cntL = (i-j-1) - cntR; //inv[j];
				dp[i] = min(dp[i], dp[j] + cntL*L + cntR*R);
			}
		}	
	}
	cout << dp[n-1] << endl;
}

