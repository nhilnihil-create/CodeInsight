#include<cstdio>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
int main()
{
	ll n;
	scanf("%lld", &n);
	while (n--)
	{
		ll q, w;
		scanf("%lld %lld", &q, &w);
		if (q == 1 && w == 1)
		{
			puts("0");
			continue;
		}
		if (q < w)
			swap(q, w);
		ll dap = w - 1;
		ll ch = (q*w);
		ch = sqrt(ch);
		dap += (ch - 1);
		ll ri = (q*w-1)/ch;
		ll le = (q*w-1 )/(q-1);
		le = max(w + 1, le);
		if (ri >= le)
			dap += (ri - le+1);
		printf("%lld\n", dap);
	}
}