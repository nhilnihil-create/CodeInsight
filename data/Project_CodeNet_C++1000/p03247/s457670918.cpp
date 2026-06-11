
#include <cstdio>

using namespace std;
const int Max_N(1050);
typedef long long int LL;

constexpr LL Abs(LL x)
{
	return x >= 0LL ? x : -x;
}

int N;
LL X[Max_N], Y[Max_N];
bool flag;

int main()
{
	scanf("%d", &N);
	for (int i = 1;i <= N;++i)
	{
		scanf("%lld%lld", X + i, Y + i);
		if ((Abs(X[1] + Y[1]) & 1) ^ (Abs(X[i] + Y[i]) & 1))
		{
			printf("-1");
			return 0;
		}
	}
	if (((Abs(X[1] + Y[1])) & 1) == 0)
	{
		flag = true;
		for (int i = 1;i <= N;++i)
			--X[i];
	}
	for (int i = 1;i <= N;++i)
	{
		LL x = X[i] + Y[i], y = X[i] - Y[i];
		X[i] = x, Y[i] = y;
	}
	if (flag)
	{
		printf("%d\n", 1 + 31);
		printf("%d ", 1);	
	}
	else
		printf("%d\n", 31);
	for (LL i = 0LL;i <= 30LL;++i)
		printf("%lld ", 1LL << i);
	printf("\n");
	for (int i = 1, gx, gy;i <= N;++i)
	{
		if (flag)
			putchar('R');
		gx = gy = 0;
		if (X[i] < 0LL)
			gx = 1, X[i] = -X[i];
		if (Y[i] < 0LL)
			gy = 1, Y[i] = -Y[i];
		for (LL j = 0LL;j <= 30LL;++j)
			X[i] += (1LL << j), Y[i] += (1LL << j);
		X[i] >>= 1LL, Y[i] >>= 1LL;
		LL Sumx = 0LL, Sumy = 0LL;
		for (LL j = 0LL, c1, c2, x, y;j <= 30LL;++j, X[i] >>= 1LL, Y[i] >>= 1LL)
		{
			c1 = (X[i] & 1LL), c2 = (Y[i] & 1LL);
			c1 = (c1 * 2LL) - 1LL, c2 = (c2 * 2LL) - 1LL;
			if (gx)
				c1 = -c1;
			if (gy)
				c2 = -c2;
			Sumx += (1LL << j) * c1, Sumy += (1LL << j) * c2;
			x = (c1 + c2) / 2LL, y = (c1 - c2) / 2LL;
			if (x == -1LL)
				putchar('L');
			if (x == +1LL)
				putchar('R');
			if (y == -1LL)
				putchar('D');
			if (y == +1LL)
				putchar('U');
		}
		puts("");
	}
	return 0;
}