#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(LL i=0;i<N;++i)
typedef long long int LL;

int main()
{
	LL N, K;
	in >> N >> K;
	out << (1 + 2 * (K - 1) <= N ? "YES" : "NO") << std::endl;
}
