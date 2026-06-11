#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, pii> pip;
typedef pair<pll, pll> P;
const ll INF = 1ll<<60;
const ll MOD = 1000000007;
const double EPS = 1e-9;
const bool debug = 0;
//---------------------------------//

int N, K;
ll a[1123], sum[1123];

int main() {
	cin >> N >> K;
	REP(i, N) scanf("%lld", a + i);
	
	sum[0] = 0;
	REP(i, N) sum[i + 1] = sum[i] + a[i];
	
	vector<ll> v;
	REP(i, N) {
		FOR(j, i, N) {
			// [i,j]
			v.push_back(sum[j + 1] - sum[i]);
		}
	}
	
	ll ans = 0;
	for (int k = 60; k >= 0; k--) {
		if (v.size() < K) break;
		sort(ALL(v), greater<ll>());
		
		if (v[K - 1] >> k & 1) {
			ans |= 1ll<<k;
			vector<ll> nextv;
			REP(i, v.size()) if (v[i] >= 1ll<<k) nextv.push_back(v[i] - (1ll<<k));
			v = nextv;
		}
		else {
			REP(i, v.size()) if (v[i] >= 1ll<<k) v[i] -= 1ll<<k;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
