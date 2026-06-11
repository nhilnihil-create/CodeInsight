// Independent set

#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<iomanip>
#define ll long long
#define mod 1000000007
using namespace std;

ll dfs(ll root,vector< vector<ll> >& adj,vector<ll>& wdp,vector<ll>& bdp,vector<bool>& visited,ll parent)
{
	ll flag=0;
	visited[root]=true;
	for(auto itr:adj[root])
	{
		if(!visited[itr])
		{
			dfs(itr,adj,wdp,bdp,visited,root);
			flag++;
		}
	}
	//do your work
	
	//leaf node
	if(flag==0)
	{
		bdp[root]=1;
		wdp[root]=1;
	}
	else
	{
		//non leafnode
		
		//when root is white
		ll tcomb=1;
		for(auto it:adj[root])
		{
			if(it!=parent)
			tcomb=(tcomb%mod)*((wdp[it]+bdp[it])%mod)%mod;
		}
		wdp[root]=tcomb;
		
		//when root is black	
		ll tcomb2=1;
		for(auto it:adj[root])
		{
			if(it!=parent)
			tcomb2=(tcomb2%mod)*(wdp[it])%mod;
		}
		bdp[root]=tcomb2;
	}
	return bdp[root]+wdp[root];
}

void solve(ll n,vector< vector<ll> >& adj)
{
	ll result=0;
	vector<ll> whitedp(n+1);
	vector<ll> blackdp(n+1);
	vector<bool> visited(n+1,false);
	
	for(ll i=1;i<=n;i++)
	{
		if(!visited[i])
		result=(result+dfs(i,adj,whitedp,blackdp,visited,-1))%mod;
	}
	
	cout<<(result)<<endl;
//	cout<<"white dp"<<endl;
//	for(auto it:whitedp)
//	cout<<it<<" ";
//	
//	cout<<endl;
//	cout<<"Black dp"<<endl;
//	for(auto itr:blackdp)
//	{
//		cout<<itr<<" ";
//	}
}

int main()
{
	ll n,x,y;
	cin>>n;
	vector< vector<ll> > adj(n+1);
	for(ll i=1;i<=n-1;i++)
	{
		cin>>x>>y;
		//directional graph
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	solve(n,adj);
	return 0;
}
