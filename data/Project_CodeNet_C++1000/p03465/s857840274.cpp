#include<bits/stdc++.h>
#include<bitset>

const int N = 2000 * 2000 + 1;
using value_type = long long;

std::bitset<N> bit;
value_type sum = 0;
int n;

inline int read()
{
	int s = 0,f = 1; char ch;
	while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
	while(isdigit(ch)) s = s * 10 + ch - '0',ch = getchar();
	return s * f;
}

int main()
{
	bit[0] = 1;
	n = read();
	for(int i = 1,x;i <= n;i++)
		x = read(),bit |= (bit << x),sum += x;
	for(auto i = (sum + 1) >> 1;i <= sum;i++)
		if(bit[i]) {
			printf("%lld",i);
			return 0;
		}

	exit(0);
}
