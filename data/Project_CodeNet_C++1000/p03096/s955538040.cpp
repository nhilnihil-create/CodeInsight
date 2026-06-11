#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<ll, ll>;

const ll MOD = 1e9+7;
const ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(ll)(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const ll MAX = 200010;
ll l[MAX]={};
ll dp[MAX]={};

int main(int argc, char **argv)
{
	ll N; cin >> N;
	vector<ll> C(N); REP(i, N) cin >> C[i];
	REP(i, MAX) l[i] = -1;

	dp[0] = 1;
	REP(i, N)
	{
		(dp[i+1] += dp[i]) %= MOD;
		ll c = C[i];
		if (l[c] >= 0 && l[c] < i-1)
			(dp[i+1] += dp[l[c]+1]) %= MOD;
		l[c] = i;
	}

	std::cout << dp[N] << std::endl;
}
