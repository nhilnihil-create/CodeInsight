#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100010, M = 13;

int n, m;
int a[N];
int p[N];

int find(int x)
{
	if (x != p[x]) p[x] = find(p[x]);
	return p[x];
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++ ) scanf("%d", a + i);
	for (int i = 0; i < N; i ++ ) p[i] = i;
	
	while (m -- )
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a = find(a), b = find(b);
		p[a] = b;
	}
	
	int res = 0;
	for (int i = 1; i <= n; i ++ )
	{
		int pa = find(i), pb = find(a[i]);
		if (pa == pb) res ++ ;
	}
	printf("%d\n", res);
	return 0;
}