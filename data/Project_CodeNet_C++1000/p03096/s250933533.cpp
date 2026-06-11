//%std
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define y1 ysgh
inline int read()
{
	int out = 0, fh = 1;
	char jp = getchar();
	while ((jp > '9' || jp < '0') && jp != '-') jp = getchar();
	if (jp == '-')
	   fh = -1, jp = getchar();
	while (jp >= '0' && jp <= '9') out = out * 10 + jp - '0', jp = getchar();
	return out * fh;
}
void print(int x)
{
	if (x >= 10)
	   print(x / 10);
	putchar('0' + x % 10);
}
void write(int x, char c = '\n')
{
	if (x < 0)
	   putchar('-'), x = -x;
	print(x);
	putchar(c);
}
namespace Module
{
	const int P = 1e9 + 7;
	int add(int a, int b) {return a + b >= P ? a + b - P : a + b;}
	void inc(int &a, int b) {a = add(a, b);}
	void dec(int &a, int b) {a = add(a, P - b);}
	int mul(int a, int b) {return 1LL * a * b % P;}
	int fpow(int a, int b)
	{
		int res = 1;
		while (b)
		{
			if (b & 1) res = mul(res, a);
			a = mul(a, a);
			b >>= 1;
		}
		return res;
	}
}
using namespace Module;
const int N = 1e6 + 10;
int n, f[N], pos[N];
int main()
{
//	freopen("magic.in", "r", stdin);
//	freopen("magic.out", "w", stdout);
	n = read();
	f[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		f[i] = f[i - 1];
		int c = read();
		int j = pos[c];
		if (j && i - 1 > j)
			inc(f[i], f[j]);
		pos[c] = i;
	}
	write(f[n]);
	return 0;
}
