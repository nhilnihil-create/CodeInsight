#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1ll<<60;


int main(int argc, char **argv)
{
	ll N, K; cin >> N >> K;
	vector<ll> x(N); for (ll i = 0; i < N; ++i) cin >> x[i];
	ll res{1ll<<60};
	for (ll i = 0; i < N-K+1; ++i)
	{
		ll left = x[i];
		ll right = x[i+K-1];
		ll tmp;
		if (right <= 0) tmp = abs(left);
		else if (left >= 0) tmp = abs(right);
		else
		{
			tmp = right - left + min(abs(right), abs(left));
		}

		res = min(res, tmp);
	}
	std::cout << res << std::endl;
}
