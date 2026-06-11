#include <bits/stdc++.h>

#define F first 
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 100010, M = 1010;

int n, m;
int a[N], p[N];

int find(int x)
{
	if (x != p[x]) p[x] = find(p[x]);
	return p[x];
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++ )
	{
		scanf("%d", &a[i]);
		p[i] = i;
	}
	
	for (int i = 0; i < m; i ++ )
	{
		int x, y;
		scanf("%d%d", &x, &y);
		
		int pa = find(x), pb = find(y);
		p[pa] = pb;
	}
	
	int res = 0;
	for (int i = 1; i <= n; i ++ )
	{
		int pa = find(a[i]), pb = find(i);
		if (pa == pb) res ++ ;
	}
	printf("%d\n", res);
    return 0;
}