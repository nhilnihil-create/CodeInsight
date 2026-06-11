#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > sp; 
vector<pair<pair<int, int>, int> > ans; 
int l, last;
vector<pair<int, int> > adj[50];

void solve(int now, int l)
{
	if(l==0)
	{
		last=now;
		return;
	}
	if(l%2==1)
	{
		adj[now].push_back({now+1, (l+1)/2});
		adj[now].push_back({now+1, 0});
		solve(now+1, l/2);
	}
	else
	{
		adj[now].push_back({now+1, (l/2)+1});
		adj[now].push_back({now+1, 0});
		solve(now+1, (l/2-1));
		sp.push_back({now, l/2});
	}
}

signed main()
{
	cin>>l;
	l--;
	solve(1, l);
	for(auto i:sp)
	{
		adj[i.first].push_back({last, i.second});
	}
	for(int i=1; i<=last; i++)
	{
		for(auto j:adj[i])
		{
			ans.push_back({{i, j.first}, j.second});
		}
	}
	cout<<last<<" "<<ans.size()<<endl;
	for(auto i:ans)
	{
		cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<endl;
	}
}