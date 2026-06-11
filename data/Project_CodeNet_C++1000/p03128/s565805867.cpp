#include <bits/stdc++.h>
#define DEBUG fprintf(stderr, "Passing [%s] line %d\n", __FUNCTION__, __LINE__)
#define itn int
#define gI gi

using namespace std;

inline int gi()
{
	int f = 1, x = 0; char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return f * x;
}

int n, m, dp[10003], a[13], bs[13] = {0,2,5,5,4,5,6,3,7,6};

inline bool cmp(int x, int y) {return x > y;}

int main()
{
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	n = gi(), m = gi();
	for (int i = 1; i <= m; i+=1) a[i] = gi();
	dp[0] = 1;
	for (int i = 1; i <= m; i+=1)
	{
		for (int j = bs[a[i]]; j <= n; j+=1)
		{
			dp[j] = max(dp[j], dp[j - bs[a[i]]] + 1);
		}
	} 
	sort(a + 1, a + 1 + m, cmp); 
	while (n)
	{
		for (int i = 1; i <= m; i+=1)
		{
			if (n >= bs[a[i]] && dp[n] == dp[n - bs[a[i]]] + 1)
			{
				printf("%d", a[i]);
				n -= bs[a[i]];
				break;
			}
		}
		//cout << n << endl;
	}
	puts("");
	return 0;
}

