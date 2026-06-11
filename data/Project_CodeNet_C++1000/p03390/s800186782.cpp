#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(int i=0;i<N;++i)
typedef long long int LL;

LL Q, A, B;

int main()
{
	in >> Q;
	rep(loop, Q)
	{
		in >> A >> B;
		if (A > B) std::swap(A, B);
		if (B - A <= 1) out << 2 * A - 2 << std::endl;
		else
		{
			LL C = sqrt(A*B);
			if (C*C == A * B) --C;
			out << (C*(C + 1) >= A * B ? 2 * C - 2 : 2 * C - 1) << std::endl;
		}
	}
	return 0;
}
