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
int p[N];

int find(int x)
{
	if (x != p[x]) p[x] = find(p[x]);
	return p[x];
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; i ++ ) p[i] = i;
	for (int i = 0; i < m; i ++ )
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		int pa = find(a), pb = find(b);
		p[pa] = pb;
	}
	
	set<int> S;
	for (int i = 1; i <= n; i ++ ) S.insert(find(i));
	printf("%d\n", S.size());
	return 0;
}