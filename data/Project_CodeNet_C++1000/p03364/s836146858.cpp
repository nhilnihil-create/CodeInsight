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

int main(int argc, char **argv)
{
	ll N; cin >> N;
	vector<string> S(N);
	REP(i, N) cin >> S[i];

	auto isOk = [&](ll a) -> bool
				{
					vector<string> tmp(N);
					REP(i, N) tmp[i] = S[(i+a)%N];
					REP(h, N)REP(w, N)
						if (tmp[h][w] != tmp[w][h])
							return false;
					return true;
				};

	ll res{0};
	REP(h, N)
		res += isOk(h);
	std::cout << res*N<< std::endl;
}
