#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
typedef long double doublel;
#define f first
#define s second
 
const int N = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e17;	

set<pair<ll, ll>> s;
int par[N], cnt[N];
ll h[N];
vector<pair<int, int>> ans;
vector<int> adj[N];


void dfs(int u)
{
	for(auto x : adj[u])
	{
		h[x] = h[u] + 1;
		dfs(x);
	}
}



int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);	
	
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		ll w;
		cin >> w;
		s.insert({-w, i});
		cnt[i] = 1;
		par[i] = i; 
		
	}
	
	bool fl = true;
	
	while(s.size() != 1)
	{
		ll w = -s.begin()->f;
		int x = s.begin()->s;
		ll w2 = w-n+2*cnt[x];
		s.erase(s.begin());


		//cout << x+1 << ' '  << w << ' ' << w2 << ' ' << fl << endl; 


		auto it = s.lower_bound({-w2, -1});
		if(it == s.end() || it->f != -w2)
			fl = false;
		else
		{
			int y = it->s;
			par[x] = y;
			cnt[y] += cnt[x];
		}		
		
	}
	
	
	
	
	for(int i = 0; i < n; i++)
	{
		if(i == par[i])
			continue;
		ans.push_back({min(i, par[i]), max(i, par[i])});
		
		adj[par[i]].push_back(i);
		
	}
	
	
	int r = s.begin()->s;
	dfs(r);
	
	ll sum = 0;
	for(int i = 0; i < n; i++)
		sum += h[i];
	
	if(sum != -s.begin()->f)
	{
		fl = false;
	}
		
	



	if(!fl)
	{
		cout << -1 << endl;
		return 0;
	}
	
	sort(ans.begin(), ans.end());
	
	for(auto e : ans)
		cout << e.f + 1 << ' ' << e.s + 1<< endl; 
	
	
	
	
	
	
	
	
	
    return 0;
}

 
 	
 	




 



