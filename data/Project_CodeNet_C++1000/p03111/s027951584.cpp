#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

int n, A[3], ans;
vector<int> l;
char tmp[8];
void check(void)
{
	vector<int> cnt(3, -1), sum(3, 0);
	int s = 0;
	rep(i, n)
	{
		sum[tmp[i] - 'A'] += l[i];
		cnt[tmp[i] - 'A']++;
	}
	rep(i, 3)
	{
		if (cnt[i] >= 0) 
			s += cnt[i] * 10;
		if (sum[i] > 0)
			s += abs(A[i] - sum[i]);
		else
			return;
	}
	ans = min(ans, s);
}

void dfs(int depth = -1, int e = -1)
{
	if (depth == n)
	{
		check();
		return;
	}	
	if (e != -1)
		tmp[depth] = 'A' + e;
	rep(i, 4)
	{
		dfs(depth + 1, i);
	}
}

signed main(void)
{
	cin >> n;
	rep(i, 3) cin >> A[i];
	l.resize(n);
	rep(i, n) cin >> l[i];
	ans = 1e9;
	dfs();
	cout << ans << endl;
	return 0;
}
