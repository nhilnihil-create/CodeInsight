#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1ll<<60;

int main(int argc, char **argv)
{
	ll N, M; cin >> N;
	map<ll, ll> D, T;
	for (ll i = 0; i < N; ++i)
	{
		ll t; cin >> t;
		++D[t];
	}
	cin >> M;
	for (ll i = 0; i < M; ++i)
	{
		ll t; cin >> t;
		++T[t];
	}

	bool ok{true};
	for (auto &p : T)
	{
		if (p.second > D[p.first])
		{
			ok = false;
			break;
		}
	}

	std::cout << (ok ? "YES" : "NO") << std::endl;
}