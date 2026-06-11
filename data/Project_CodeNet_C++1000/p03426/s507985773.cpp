#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

ll dp[300*300+10];
ll dy[300*300+10];
ll dx[300*300+10];

int main(int argc, char **argv)
{
	ll H, W, D; cin >> H >> W >> D;
	REP(h, H)REP(w, W)
	{
		ll a; cin >> a;
		dy[a] = h;
		dx[a] = w;
	}

	memset(dp, 0, sizeof dp);

	for (ll i = D+1; i <= H*W; ++i)
	{
		ll k = i - D;
		dp[i] = dp[k] + abs(dy[i] - dy[k]) + abs(dx[i] - dx[k]);
	}

	ll Q; cin >> Q;
	REP(_, Q)
	{
		ll a, b; cin >> a >> b;
		std::cout << dp[b] - dp[a] << std::endl;
	}
}