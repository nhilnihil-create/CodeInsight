#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(ll)(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

int main(int argc, char **argv)
{
	ll N;cin >> N;
	vector<ll> h(N);
	REP(i, N) cin >> h[i];

	ll pre{0};
	ll res{0};
	REP(i, N)
	{
		res += max(0ll, h[i] - pre);
		pre = h[i];
	}

	std::cout << res << std::endl;
}
