#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <class T>
void chmin(T &a, T b) {if (a > b) a = b;}

int main(int argc, char **argv)
{
	ll N; cin >> N;
	vector<ll> TARGET(N); for (ll i = 0; i < 3; ++i) cin >> TARGET[i];
	vector<ll> L(N); for (ll i = 0; i < N; ++i) cin >> L[i];

	vector<ll> bits(3);

	ll res{1ll<<60};
	for (bits[0] = 1; bits[0] < (1 << N); ++bits[0])
	{
		for (bits[1] = 1; bits[1] < (1 << N); ++bits[1])
		{
			if (bits[0] & bits[1]) continue;
			for (bits[2] = 1; bits[2] < (1 << N); ++bits[2])
			{
				if (bits[1] & bits[2] || bits[0] & bits[2]) continue;

				vector<ll> sum_l(3, 0);
				ll num_l{0};
				for (ll l = 0; l < N; ++l)
				{
					for (ll i = 0; i < 3; ++i)
					{
						if (bits[i] & (1 << l))
						{
							sum_l[i] += L[l];
							++num_l;
						}
					}
				}

				ll tmp = (num_l - 3) * 10;
				for (ll i = 0; i < 3; ++i)
					tmp += abs(TARGET[i] - sum_l[i]);
				
				chmin(res, tmp);
				
			}
		}
	}
	std::cout << res << std::endl;
	
}
