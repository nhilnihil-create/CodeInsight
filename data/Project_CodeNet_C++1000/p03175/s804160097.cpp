#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
#define fr(i,k,n) for (int i = k; i < n; ++i)
#define fri(i,k,n) for (int i = k; i >= n; --i)
#define INF (int)1e9
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define all(arr) arr.begin(),arr.end()

void boost(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int N=1e5+5;
vi adj[N];

pll dfs(int u,int p){
	pll cur={1,1};
	pll temp;
	for(auto v: adj[u]){
		if(v!=p){
			temp=dfs(v,u);
			cur.first=(cur.first * temp.second)%MOD;
			cur.second=(cur.second * (temp.first+temp.second))%MOD;
		}
	}
	return cur;
}

void solve(){
	int n;
	cin>>n;
	int u,v;
	fr(i,0,n-1){
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	pll ans=dfs(1,0);
	cout<<(ans.first + ans.second)%MOD <<endl;
	return;
}

int main()
{
	boost();
	
	int tc=1;
	//cin>>tc;
	while(tc--)
		solve();
	return 0;
}