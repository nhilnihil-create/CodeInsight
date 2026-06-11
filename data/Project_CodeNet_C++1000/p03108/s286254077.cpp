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
int p[N], SIZE[N];
PII bri[N];
vector<LL> res;

int find(int x)
{
	if (x != p[x]) p[x] = find(p[x]);
	return p[x];
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i ++ ) scanf("%d%d", &bri[i].F, &bri[i].S);
	for (int i = 0; i <= n; i ++ ) p[i] = i, SIZE[i] = 1;
	
	LL tot = (LL)n * (n - 1) / 2LL;
	for (int i = m - 1; i >= 0; i -- )
	{
		res.PB(tot);
		int pa = find(bri[i].F), pb = find(bri[i].S);
		
		if (pa != pb)
		{
			tot -= (LL)SIZE[pa] * SIZE[pb];
			SIZE[pb] += SIZE[pa];
			p[pa] = pb;
		}
	}
	
	reverse(res.begin(), res.end());
	for (auto u : res) printf("%lld\n", u);
    return 0;
}