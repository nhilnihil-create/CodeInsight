#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(int i=0;i<N;++i)
typedef long long int LL;

LL a, b;

int main()
{
	in >>a >> b;
	if (a + b == 15) out << "+" << std::endl;
	else if (a*b == 15) out << "*" << std::endl;
	else out << "x" << std::endl;
	return 0;
}
