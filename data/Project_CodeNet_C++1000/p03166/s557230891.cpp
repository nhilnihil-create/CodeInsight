#include <bits/stdc++.h>
#include <iostream>

using namespace std;
//DAG DP(Topological Sort), Tree DP

//State
//dp[i]: The length of the largest path in DAG (G_dash) 
// containing first i vertices in the topological sort order of G

//Initialization
//For all nodes i whose indegree is 0 set dp[i] = 0 and put them in a queue

//Transitions //Forward DP
//For all v E children(i): dp[v] = max(dp[v], dp[i]+w(i->v))

//Order of evaluation
//Topological sort order

//Answer 
//max(dp[0...n-1])

int main(){
	int N, M;
	cin >> N >> M;
	vector<vector<int>> adjList(N,vector<int>(0));
	vector<int> inDegree(N, 0);
	vector<int> dp(N,0);
	int x, y;
	for(int i=0; i<M; i++){
		cin >> x >> y;
		x = x-1;
		y = y-1;
		adjList[x].push_back(y);
		inDegree[y] = inDegree[y]+1;
	}
	queue<int> q;
	for(int i=0; i<N; i++){
		if(inDegree[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int parent = q.front();
		q.pop();
		vector<int> children = adjList[parent];
		for(int v: children){
			dp[v] = max(dp[v], dp[parent]+1);
			inDegree[v] = inDegree[v]-1;
			if(inDegree[v]==0) q.push(v);
		}
	}

	int result = 0;
	for(int i=0; i<N; i++){
		result = max(result, dp[i]);
	}
	cout << result << endl;

}
