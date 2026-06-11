#include <bits/stdc++.h>
#define LL long long
#define ri register int
#define pii pair<int, int>
#define pll pair<LL, LL>
using namespace std;
inline int read()
{
	int ret = 0; char ch = getchar();
	while(ch < '0' || ch > '9')
		ch = getchar();
	do {
		ret = ret * 10 + ch - '0';
		ch = getchar();
	} while('0' <= ch && ch <= '9');
	return ret;
}
inline void write(int x) // x > 0 (x != 0) ***
{
	if(!x)
		return ;
	write(x / 10);
	putchar(x % 10 + '0');
}
#define mod 1000000007
#define maxn 100100
inline LL fpow(LL x, LL a)
{
	LL ret = 1;
	while(a)
	{
		if(a & 1)
			ret = ret * x % mod;
		a >>= 1;
		x = x * x % mod;
	}
	return ret;
}
int n;
LL ni[maxn];
LL peng = 1;
LL sum[maxn];
LL a[maxn];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i ++)
		ni[i] = fpow(i, mod - 2);
	for(int i = 1; i <= n; i ++)
		peng = peng * i % mod;
	for(int i = 1; i <= n; i ++)
		sum[i] = (sum[i - 1] + peng * ni[i]) % mod;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	LL Ans = 0;
	for(int i = 1; i <= n; i ++)
	{
		Ans = (Ans + a[i] * (sum[i] - sum[1] + sum[n - i + 1])) % mod;
	}
	cout << Ans << endl;
	return 0;
}

