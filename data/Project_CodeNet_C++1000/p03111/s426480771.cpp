#include <bits/stdc++.h>

#define F first 
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 10, M = 1010, INF = 0x3f3f3f3f;

int n, a, b, c;
int len[N];

int dfs(int u, int sa, int sb, int sc, int cnt)
{
	if (u >= n)
	{
		if (!sa || !sb || !sc) return INF;
		else return abs(a - sa) + abs(b - sb) + abs(c - sc) + (cnt - 3) * 10;
	}
	
	int res = INF;
	res = min(res, dfs(u + 1, sa, sb, sc, cnt));
	res = min(res, dfs(u + 1, sa + len[u], sb, sc, cnt + 1));
	res = min(res, dfs(u + 1, sa, sb + len[u], sc, cnt + 1));
	res = min(res, dfs(u + 1, sa, sb, sc + len[u], cnt + 1));
	return res;
}

int main()
{
	cin >> n >> a >> b >> c;
	for (int i = 0; i < n; i ++ ) cin >> len[i];
	cout << dfs(0, 0, 0, 0, 0) << endl;
    return 0;
}