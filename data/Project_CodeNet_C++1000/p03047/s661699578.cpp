#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define ff first
#define ss second
#define se set<ll>
#define vec vector<ll>
#define inf 10000000000000000
bool mark[100005];
vec adj[100005];
ll counter;
vec cnt;
ll b;
ll a;

void addedge(ll u, ll v)

	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

bool dfs(ll node)
	{
		cout<<node<<endl;
		mark[node]=1;
		

		for(auto i:adj[node])
		{	
			if(!mark[i])
				dfs(i);
		}			

			
	}

int main()
{    
 

	#ifdef APNA_IO
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
		    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

 ll n,k;
 cin>>n>>k;
 cout<<n-k+1<<endl;
}		



