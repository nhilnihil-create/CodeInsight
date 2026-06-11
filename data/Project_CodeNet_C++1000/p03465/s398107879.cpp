#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = (x << 1) + (x << 3) + ch - '0';
	return x * f;
}

const int N = 4e6 + 5;;

bitset<N> f;

int main()
{
	int n = read(), sum = 0;
	f[0] = 1;
	
	for (int i = 1, x; i <= n; ++i)
	{
		sum += (x = read());
		f |= f << x;
	}
	
	for (int i = (sum + 1) / 2; i <= sum; ++i)
		if (f[i]) { printf("%d\n", i); break; }
	
	return 0;
}
