#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>

#define lowbit(x) (x&(-x))
#define MAX(a,b) (a<b?b:a)
#define MIN(a,b) (a<b?a:b)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N = 1e7;
const int maxn = 3e2 + 5;
ll mod = 1e9 + 7;

char s[maxn];
int k;

int f[maxn][maxn][maxn];

int main()
{
	scanf("%s%d", s, &k);
	int n = strlen(s);
	if (n == 1)
	{
		printf("1");
		return 0;
	}
	for (int i = 0; i < n; i++) f[i][i][0] = 1;

	for(int len = 2;len<=n;++len)
	{
		for(int l = 0;l<n;l++)
		{
			int r = l + len - 1;
			if (r >= n) break;
			for (int x = 0; x <= k; x++)
			{
				f[l][r][x] = MAX(f[l + 1][r][x], f[l][r - 1][x]);
				if (s[l] == s[r]) f[l][r][x] = MAX(f[l][r][x], f[l + 1][r - 1][x] + 2);
				if (x)
				{
					f[l][r][x] = MAX(f[l][r][x], f[l][r][x - 1]);
					f[l][r][x] = MAX(f[l][r][x], f[l + 1][r - 1][x - 1] + 2);
				}
			}
		}
	}
	
	printf("%d", f[0][n - 1][k]);
}