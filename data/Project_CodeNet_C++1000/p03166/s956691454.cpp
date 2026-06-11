#include<bits/stdc++.h>

#define REP(i,n) for(int i=0; i<n; i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod1 1000000007
#define ll long long
#define clr0(arr) memset(arr,0,sizeof(arr))
#define clrval(arr,val) memset(arr,val,sizeof(arr))
using namespace std;

void showList(vector<int>adj[], int n){

	for(int u=1; u<=n; u++){
		cout<<u<<" -> ";

		for(auto it=adj[u].begin(); it!=adj[u].end(); it++){
			cout<<*it<<" ";
		}
		cout<<"\n";
	}
}

void dfsUtil(vector<int>adj[], int ele, bool visited[]){

	if(visited[ele])
		return;

	cout<<ele<<" ";
	visited[ele]=true;

	for(auto it=adj[ele].begin(); it!=adj[ele].end(); it++){
		dfsUtil(adj,*it,visited);
	}
}

void dfs(vector<int>adj[], int n){

	bool visited[n+1];
	REP(i,n+1)
		visited[i]=false;

	for(int u=1; u<=n; u++){
		dfsUtil(adj,u,visited);
	}

	cout<<"\n";
}

int dp[100010];

int solveUtil(vector<int>adj[], int ele){

	if(dp[ele] != -1)
		return dp[ele];

	int ans=0;
	for(auto it=adj[ele].begin(); it!=adj[ele].end(); it++){
		int tempAns = 1 + solveUtil(adj,*it);

		ans=max(ans,tempAns);
	}

	dp[ele] = ans;
	return ans;
}

int solve(vector<int>adj[], int n){

	clrval(dp,-1);

	int ans=1;
	for(int u=1; u<=n; u++){
		ans=max(ans,solveUtil(adj,u));
	}

	return ans;
}

void bfs(vector<int>adj[], int n){
	queue<int> q;     
	q.push(1);      
	bool visited[n+1] = {false};     

	while(q.empty() == false){          
		int temp = q.front();         
		q.pop();         
		cout<<temp<<" ";         
		visited[temp]=true;          

		for(auto it = adj[temp].begin(); it!=adj[temp].end(); it++){              
			if(visited[*it]==false)                 
				q.push(*it);          
		}
	} 
}

void addEdge(int u, int v, vector<int>adj[]){
	adj[u].push_back(v);
	// adj[v].push_back(u);
}

int main(){

	int n,m;
	cin>>n>>m; //input

	vector<int>adj [n+1];

	REP(i,m){
		int u,v;
		cin>>u>>v;

		addEdge(u,v,adj);
	}

	// showList(adj,n);
	// dfs(adj,n);
	// bfs(adj,n);

	cout<<solve(adj,n)<<"\n";

	return 0;
}
