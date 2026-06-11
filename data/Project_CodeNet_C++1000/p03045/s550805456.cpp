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

vector<int> g[N]; 
int was[N];
void dfs(int v)
{
	if (was[v])
	{
		return;
	}
	was[v] = 1;
	for (int i = 0; i < g[v].size(); i++)
	{
		dfs(g[v][i]);
	}
}
int main() 
{
    scan();     
    int n, m;
    cin >> n >> m;        
    for (int i = 1; i <= m; i++)
    {
    	int a, b, c;
    	cin >> a >> b >> c;
    	g[a].pb(b);
    	g[b].pb(a);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
    	if (was[i])
    	{
    		continue;
    	}
    	dfs(i);
    	ans++;
    }
    cout << ans;
}     
//JUDGE_ID: 295965SY
//Tis I