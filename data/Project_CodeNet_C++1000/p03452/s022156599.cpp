#include<bits/stdc++.h>
#define pb push_back
#define ins insert
#define F first
#define S second
#define var auto
using namespace std;
typedef long long ll;
const int Max = 1e5 + 10;
const int Mod = 1e9 + 7;


bool seen[Max];
vector<pair<int,int> > N[Max];

bool ok = true;
int dist[Max];

void DFS(int v)
{
	seen[v] = true;

	for(auto u : N[v])
	{
		if(seen[u.F])
			ok &= dist[u.F] == dist[v] + u.S;
		else
		{
			dist[u.F] = dist[v] + u.S;
			DFS(u.F);
		}
	}
}

int main()
{
	int n , m;cin >> n >> m;
	for(int i = 0; i < m ; i++)
	{
		int l , r , d;cin >> l >> r >> d;
		N[l].pb({r , d});
		N[r].pb({l , -d});
	}
	for(int i = 1; i <= n ; i++)
	{
		if(!seen[i])
		{
			dist[i] = 0;
			DFS(i);
		}
	}
	if(ok)
		cout << "Yes\n";
	else
		cout << "No\n";
}

