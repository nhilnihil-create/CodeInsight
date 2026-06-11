#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<ll, ll>;

const ll MOD = 1e9+7;
// const ll MOD = 998244353;
const ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(ll)(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

ll K;
vector<ll> A;

int main(int argc, char **argv)
{
	cin >> K;
	A.resize(K);
	REP(i, K) cin >> A[i];
	reverse(ALL(A));

	P ok;
	ok.first = ok.second = 2;
	REP(i, K)
	{
		ll l = ok.first;
		ll r = ok.second;

		ll ln = (l + A[i] - 1)/ A[i];
		ll rn = r/ A[i];

		if (ln > rn)
		{
			std::cout << -1 << std::endl;
			return 0;
		}

		ok.first = ln*A[i];
		ok.second = rn*A[i] + A[i]-1;
	}

	std::cout << ok.first << " " << ok.second << std::endl;
}
