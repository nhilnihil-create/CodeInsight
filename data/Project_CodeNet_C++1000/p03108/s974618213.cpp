#include <bits/stdc++.h>

#define F first 
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HI;
typedef priority_queue<int, vector<int>, greater<int> > HDI;

const int N = 100010, M = 1010;

int n, m;
int a[N], b[N];
int p[N], size[N];
vector<LL> res;

int find(int x)
{
	if (x != p[x]) p[x] = find(p[x]);
	return p[x];
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; i ++ ) p[i] = i, size[i] = 1;
	
	for (int i = 0; i < m; i ++ ) scanf("%d%d", &a[i], &b[i]);
	
	LL tot = (LL)(n - 1) * n / 2LL;
	res.push_back(tot);
	for (int i = m - 1; i; i -- )
	{
		int aa = find(a[i]), bb = find(b[i]);
		if (aa != bb)
		{
			tot -= (LL)size[aa] * size[bb];
			size[bb] += size[aa];
			p[aa] = bb;
		}
		res.push_back(tot);
	}
	reverse(res.begin(), res.end());
	
	for (auto u : res) printf("%lld\n", u);
    return 0;
}