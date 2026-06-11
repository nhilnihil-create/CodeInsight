#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <set>
#define lowbit(x) (x&(-x))
#define MAX(a,b) (a<b?b:a)
#define MIN(a,b) (a<b?a:b)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5;
const int maxn = 3e5 + 5;
ll mod = 1e9 + 7;

int n;
int a[maxn],maxd[maxn],smax[maxn], f[maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < (1 << n); i++) scanf("%d", a + i);
	maxd[0] = 0; smax[0] = (1<<n);
	for (int i = 1; i < (1 << n); i++)
	{
		maxd[i] = i; smax[0] = (1 << n);
		for (int j = 0; i >> j; j++) if((i>>j)&1)
		{
			if (a[maxd[i ^ (1 << j)]] > a[maxd[i]])
			{
				smax[i] = maxd[i];
				maxd[i] = maxd[i ^ (1 << j)];
			}
			else if (maxd[i^(1<<j)] != maxd[i] && a[maxd[i ^ (1 << j)]] > a[smax[i]])
			{
				smax[i] = maxd[i^(1<<j)];
			}
		}
	}
	
	for (int i = 1; i < (1 << n); i++)
	{
		f[i] = max(f[i - 1], a[maxd[i]] + a[smax[i]]);
		printf("%d\n", f[i]);
	}
}