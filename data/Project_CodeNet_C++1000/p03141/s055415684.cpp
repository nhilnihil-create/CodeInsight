#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

int main(int argc, char **argv)
{
	ll N; cin >> N;

	vector<ll> AB(N), A(N), B(N);
	
	REP(i, N)
	{
		cin >> A[i] >> B[i];
		AB[i] = A[i] + B[i];
	}

	ll res = -accumulate(B.begin(), B.end(), 0ll);

	vector<ll> index(N);
	iota(ALL(index), 0ll);

	sort(ALL(index), [&](auto &a, auto &b)
					 {
						 return AB[a] > AB[b];
					 });

	bool ist{true};

	REP(i, N)
	{
		if (ist)
			res += AB[index[i]];
		ist ^= true;
	}

	std::cout << res << std::endl;
}
