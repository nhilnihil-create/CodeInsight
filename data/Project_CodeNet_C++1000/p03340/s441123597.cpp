#include <bits/stdc++.h>

#define F first 
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 200010, M = 25;

int n;
int a[N], cnt[N][M];

bool check(int x, int y)
{
	for (int i = 0; i < M; i ++ )
		if (cnt[y][i] - cnt[x][i] >= 2)
			return false;
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++ )
	{
		scanf("%d", &a[i]);
		for (int j = 0; j < M; j ++ )
		{
			cnt[i][j] += (a[i] >> j) & 1;
			cnt[i][j] += cnt[i - 1][j];
		}
	}
	
	LL res = 0;
	for (int i = 1; i <= n; i ++ )
	{
		int l = 0, r = i - 1;
		while (l < r)
		{
			int mid = l + r >> 1;
			if (check(mid, i)) r = mid;
			else l = mid + 1;
		}
		res += i - r;
	}
	printf("%lld\n", res);
    return 0;
}