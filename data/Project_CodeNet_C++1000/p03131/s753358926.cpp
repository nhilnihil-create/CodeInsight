#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1ll<<60;

int main(int argc, char **argv)
{
	ll K, A, B; cin >> K >> A >> B;
	if (1 + A >= B)
		std::cout << K + 1 << std::endl;
	else
	{
		ll res{1};
		while (K)
		{
			if (res < A || K <= 1)
			{
				++res;
				--K;
			}
			else
			{
				res += B - A;
				K -= 2;
			}
		}
		std::cout << res << std::endl;
	}
}
