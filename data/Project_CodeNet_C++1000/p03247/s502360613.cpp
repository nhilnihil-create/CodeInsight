#include<bits/stdc++.h>
using namespace std;
int n, x[100007], y[100007], l[57], is[2], cnt;
int read()
{
	int num = 0, f = 1;
	char c = getchar();
	while ((c < '0' || c>'9') && c != '-')c = getchar();
	if (c == '-')f = -1, c = getchar();
	while (c >= '0' && c <= '9')num = num * 10 + c - '0', c = getchar();
	return num * f;
}
int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
	{
		x[i] = read(), y[i] = read();
		is[(x[i] + y[i]) & 1] = 1;
	}
	if (is[0] && is[1]) { cout << -1 << endl; return 0; }
	if (is[0])l[++cnt] = 1;
	for (int i = 30; i >= 0; i--)l[++cnt] = 1 << i;
	cout << cnt << endl;
	for (int i = 1; i <= cnt; i++)cout << l[i] << ' ';
	cout << endl;
	for (int i = 1; i <= n; i++)
	{
		int a = x[i], b = y[i];
		for (int j = 1; j <= cnt; j++)
			if (abs(a) >= abs(b))
				if (a > 0)a -= l[j], putchar('R');
				else a += l[j], putchar('L');
			else
				if (b > 0)b -= l[j], putchar('U');
				else b += l[j], putchar('D');
		putchar('\n');
	}
	return 0;
}