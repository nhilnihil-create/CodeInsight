#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5+10;
int n, a[N], b[N], c[2], d[N];
char s[N];
int Abs(int x){return x > 0 ? x : -x;}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &a[i], &b[i]);
		++c[(a[i] + b[i]) & 1];
    }
    if (c[0] != n && c[1] != n)
    {
    	puts("-1");
		return 0;
    }
    printf("%d\n", 31 + (c[0] != 0));
	for (int i = 0; i <= 30; i++)
		printf("%d ", 1 << i);
	if (c[0])
		printf("1 ");
	putchar(10);
	for (int i = 1; i <= n; i++)
	{
		int x = a[i], y = b[i];
		if (c[0])
			--x, s[31] = 'R';
		int f = 0;
        for (int i = 30; i >= 0; i--)
        {
            if (Abs(x) < Abs(y))
            	swap(x, y), f ^= 1;
			if (x > 0)
				x -= 1 << i, s[i] = "RU"[f];
			else
				x += 1 << i, s[i] = "LD"[f];
		}
		puts(s);
    }
}