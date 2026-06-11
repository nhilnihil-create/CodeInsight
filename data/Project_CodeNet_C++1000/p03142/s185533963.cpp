#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

vector<int> out[maxn] , in[maxn];

int pos[maxn] , sz;

bool visited[maxn];

void dfs(int v)
{
	visited[v] = 1;
	for(auto u : out[v])
		if(!visited[u])
			dfs(u);

	pos[v] = sz++;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , m;
	cin >> n >> m;

	for(int i = 0; i < n - 1 + m; i++)
	{
		int a , b;
		cin >> a >> b;
		a-- , b--;

		out[a].pb(b);
		in[b].pb(a);
	}

	for(int i = 0; i < n; i++)
		if(!visited[i])
			dfs(i);

	for(int i = 0; i < n; i++)
	{
		pair<int , int> mn = {1e9 , 0};
		for(auto u : in[i])
			mn = min(mn , make_pair(pos[u] , u + 1));

		cout << mn.second << endl;
	}
}








