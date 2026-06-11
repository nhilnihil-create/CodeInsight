#include <bits/stdc++.h>
 
#define pb push_back
#define ll long long        
using namespace std;
 
void scan()
{
    #ifdef NURS
        freopen("main.in", "r", stdin);
        freopen("main.out", "w", stdout);
    #endif
 
}
const int N = 1e6 + 500;
const int mod = 1e9 + 7;
 
vector<pair<int,int>> g[N];
int ans[N];
void dfs(int v, int p,  int s)
{
	if (s % 2 == 0)
	{
		ans[v] = 0;
	}
	else 
	{
		ans[v] = 1;
	}
	for (int i = 0; i < g[v].size(); i++)
	{
		if (g[v][i].first == p)
		{
			continue;	
		}
		dfs(g[v][i].first, v, s + g[v][i].second);
	}
}
int main() 
{
    scan();     
    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
    	int u, v;
    	cin >> u >> v;
    	int w;
    	cin >> w;
    	g[u].pb({v, w});
    	g[v].pb({u, w});
    }
    int start = -1;
    for (int i = 1; i <= n; i++)
    {
    	if (g[i].size() == 1)
    	{
    		start = i;
    		break;
    	}
    }
    dfs(start, -1, 0);
    for (int i = 1; i <= n; i++)
    {
    	cout << ans[i] << " ";
    }
}     
//JUDGE_ID: 295965SY
//Tis I