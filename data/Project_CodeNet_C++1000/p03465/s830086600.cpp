#include <bits/stdc++.h>
using namespace std;
const int maxb = 2000 * 2000 + 5;
bitset<maxb> f;
int n, sum;
int main()
{
	scanf("%d", &n);
	f[0] = 1;
	for(int i = 1; i <= n; ++i)
	{
		int val;
		scanf("%d", &val);
		sum += val;
		f = f | (f << val);
	}
	for(int i = (sum + 1) / 2; i <= sum; ++i)
		if(f[i])
		{
			printf("%d\n", i);
			return 0;
		}
	return 0;
}