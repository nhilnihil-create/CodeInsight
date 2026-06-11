#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1ll<<60;

	
int main(int argc, char **argv)
{
	ll N, M; cin >> N >> M;
	vector<ll> X[3];
	for (ll i = 0; i < N; ++i)
		for (ll j = 0; j < 3; ++j)
		{
			ll num; cin >> num;
			X[j].push_back(num);
		}
	ll res{0};
	for (ll bits = 0; bits < (1 << 3); ++bits)
	{
		vector<ll> b;
		for (ll i = 0; i < N; ++i)
		{
			ll tmp{0};
			for (ll j = 0; j < 3; ++j)
			{
				if (bits & (1 << j)) tmp -= X[j][i];
				else tmp += X[j][i];
			}
			b.push_back(tmp);
		}
		sort(b.begin(), b.end(), greater<ll>());
		ll sum = accumulate(b.begin(), next(b.begin(), M), 0ll);
		res = max(res, sum);
	}
	std::cout << res << std::endl;
}
