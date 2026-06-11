#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100010, M = 110, mod = 1e9 + 7;

int n, m;
int p[N], sz[N];
PII e[N];
vector<LL> res;

int find(int x)
{
	if (x != p[x]) p[x] = find(p[x]);
	return p[x];
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; i ++ ) p[i] = i, sz[i] = 1;
	
	for (int i = 0; i < m; i ++ )
	{
		int a, b;
		scanf("%d%d", &a, &b);
		e[i] = {a, b};
	}
	for (int i = m - 1; i >= 0; i -- )
	{
		int a = e[i].F, b = e[i].S;
		int pa = find(a), pb = find(b);
		if (pa != pb)
		{
			res.push_back((LL)sz[pa] * sz[pb]);
			sz[pa] += sz[pb];
			p[pb] = pa;
		}
		else res.push_back(0);
	}
	
	reverse(res.begin(), res.end());
	LL s = 0;
	for (int i = 0; i < res.size(); i ++ )
	{
		s += res[i];
		cout << s << endl;
	}
	return 0;
}