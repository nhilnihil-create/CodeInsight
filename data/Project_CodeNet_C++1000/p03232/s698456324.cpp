#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(LL i=0;i<N;++i)
typedef long long int LL;

const LL mod = 1000000007;

// ユークリッドの互除法
LL extgcd(LL a, LL b, LL &x, LL &y)
{
	LL g = a; x = 1; y = 0;
	if (b != 0)
	{
		g = extgcd(b, a%b, y, x);
		y -= (a / b)*x;
	}
	return g;
}

// 逆元
LL mod_inverse(LL a, LL m)
{
	LL x, y;
	extgcd(a, m, x, y);
	return (m + x % m) % m;
}

// 階乗
std::vector<LL>fact;
void mod_fact(LL n, LL m)
{
	fact.resize(n + 1);
	fact[0] = 1;
	for (LL i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i%m;
}

int main()
{
	LL N;
	in >> N;
	std::vector<LL>A(N);
	rep(i, N) in >> A[i];

	std::vector<LL>B(N + 1);
	LL perm = 0, ans = 0;
	mod_fact(N, mod);
	rep(i, N)
	{
		B[i] = (fact[N] * mod_inverse(i + 1, mod)) % mod;
		(perm += B[i]) %= mod;
	}
	rep(i, N)
	{
		(ans += (A[i] * perm) % mod) %= mod;
		if (i < N - 1)
		{
			(perm += B[i + 1]) %= mod;
			((perm -= B[N - i - 1]) += mod) %= mod;
		}
	}

	out << ans << std::endl;
}
