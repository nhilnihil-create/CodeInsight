#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1ll<<60;

int main(int argc, char **argv)
{
	ll N, H; cin >> N >> H;
	vector<ll> A(N), B(N);
	for (ll i = 0; i < N; ++i)
		cin >> A[i] >> B[i];

	sort(B.begin(), B.end(), greater<ll>());
	ll amax = *max_element(A.begin(), A.end());
	ll res{0};
	for (ll i = 0; (i < N && H > 0); ++i)
	{
		if (B[i] > amax)
		{
			H -= B[i];
			++res;
		}
		else
			break;
	}

	H = max(0ll, H);
	if (H % amax == 0)
		res += H/amax;
	else
		res += H/amax+1;
	std::cout << res << std::endl;
}
