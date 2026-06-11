#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1ll<<60;

int main(int argc, char **argv)
{
	ll N; cin >> N;
	vector<ll> B(N);
	for (ll i = 0; i < N; ++i)
		cin >> B[i];

	vector<ll> res(N);
	for (ll i = 0; i < N; ++i)
	{
		ll d{-1};
		for (ll j = 0; j < (ll)B.size(); ++j)
		{
			if (j+1 == B[j])
				d = j;
		}
		if (d == -1)
		{
			std::cout << -1 << std::endl;
			return 0;
		}

		res[i] = d+1;
		B.erase(next(B.begin(), d));
	}
	for (auto it = res.rbegin(); it != res.rend(); ++it)
		std::cout << *it << std::endl;
}