#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_N = 10005;
vector<int> G[MAX_N],c;
int ans[MAX_N];
bool visited[MAX_N];
int idx = 0;

void dfs(int n)
{
	if (visited[n]) return;
	visited[n] = true;
	ans[n] = c[idx];
	idx++;
	rep(i,G[n].size())
	{
		dfs(G[n][i]);
	}
	return;
}

int main()
{
	int N;
	cin >> N;
	rep(i,N-1)
	{
		int a,b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	rep(i,N)
	{
		int p;
		cin >> p;
		c.push_back(p);
	}
	sort(c.begin(), c.end());
	reverse(c.begin(), c.end());
	dfs(0);
	ll M = 0;
	rep(i,N-1)
	{
		M += c[i+1];
	}
	cout << M << endl;
	rep(i,N)
	{
		if (i != 0) cout << " ";
		cout << ans[i];
	}
	return 0;
}