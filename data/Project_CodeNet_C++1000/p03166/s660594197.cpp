/*@author Vipen Loka*/
#include <bits/stdc++.h>
#define endl '\n'
#define ff first
#define ss second
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define deb(x) cout << #x << ':' << x << '\n';

using namespace std;
class Graph{
	int n;
	list<int> *graph;
	vector<int> dp;
public:
	int ans=0;
	Graph(int n){
		this->n=n;
		graph=new list<int>[n];
		dp.assign(n,0);
	}
	void addEdge(int a,int b){
		a--;b--;
		graph[a].push_back(b);
	}

	void dfs(int s,bool* &visited){
		visited[s]=1;

		for(auto &x:graph[s]){
			if(!visited[x])dfs(x,visited);
			// dfs(x,visited);
			dp[s]=max(dp[s],dp[x]+1);
			ans=max(dp[s],ans);
		}
	}

	void dfs(){
		bool *visited=new bool[n];
		for (int i = 0; i < n; i++)
		{
			visited[i]=0;
		}
		for (int i = 0; i < n; ++i)
		{
			if(visited[i])continue;
			dfs(i,visited);
		}
	}


};
void solve(){
	int i,j;
	int n,e;
	cin >> n >> e;
	Graph g(n);
	for (int i = 0; i < e; ++i)
	{	
		int a,b;cin >> a >> b;
		g.addEdge(a,b);
	}

	g.dfs();

	printf("%d\n",g.ans);
}


int main(){
	int T=1;
	// cin >> T;
	while (T--){
		solve();
	}
}
