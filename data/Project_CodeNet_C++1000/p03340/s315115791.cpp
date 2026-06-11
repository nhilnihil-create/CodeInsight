#include <bits/stdc++.h>

#define F first 
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 200010, M = 45;

int n;
int cnt[N][M];
LL a[N];

bool check(int x, int y)
{
	for (int i = 0; i < M; i ++ )
		if (abs(cnt[x][i] - cnt[y][i]) >= 2)
			return false;
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++ )
	{
		scanf("%lld\n", &a[i]);
		for (int j = 0; j < M; j ++ ) cnt[i][j] += (a[i] >> j) & 1;
	}
	
	for (int i = 1; i <= n; i ++ )
		for (int j = 0; j < M; j ++ )
			cnt[i][j] += cnt[i - 1][j];
	
	LL res = 0;
	for (int i = 1; i <= n; i ++ )
	{
		int l = 0, r = i - 1;
		while (l < r)
		{
			int mid = l + r >> 1;
			if (check(i, mid)) r = mid;
			else l = mid + 1;
		}
		res += i - r - 1;
	}
	printf("%lld\n", res + n);
    return 0;
}