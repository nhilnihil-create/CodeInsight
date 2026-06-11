#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

ll toh[300*300+10];
ll tow[300*300+10];
ll dp[300*300+10];

int main(int argc, char **argv)
{
	ll H, W, D; cin >> H >> W >> D;
	REP(h, H)REP(w, W)
	{
		ll a; cin >> a;
		toh[a] = h;
		tow[a] = w;
	}

	memset(dp, 0, sizeof dp);

	for (ll i = D+1; i <= H*W; ++i)
	{
		ll k = i - D;
		dp[i] = dp[k] + abs(toh[i] - toh[k]) + abs(tow[i] - tow[k]);
	}

	ll Q; cin >> Q;
	REP(_, Q)
	{
		ll l, r; cin >> l >> r;
		std::cout << dp[r] - dp[l] << std::endl;
	}
}
