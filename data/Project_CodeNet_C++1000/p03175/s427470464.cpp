#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//State
//dp[i][k]: The number of ways of coloring the subtree rooted
// at i can be colored with i being colored white(k=0) or i being colored black(k=1)

//Initialization
//For all nodes i with no children(leaf nodes) dp[i][0] = 1 and dp[i][1]=1

//Transitions: If root is white the children can be ehite or black but if root is black children must be white
//dp[parent][0] = max(dp[child1][0],dp[child1][1]) + max(dp[child2][0],dp[child2][1]) + max(dp[child3][0],dp[child3][1])
//dp[parent][1] = dp[child1][0] + dp[child2][0] +dp[child3][0]

//Order of Evaluation
//DFS

//Answer
//dp[root][0]+dp[root][1] Sum this over all connected components

//Time Complexity: O(N)

const long long mod = 1e9+7;
long long dp[100005][2] = {0};
long long visited[100005] = {false};
vector<vector<long long>> adjList(100005, vector<long long>(0));
long long N;

void dfs(long long node, long long parent){
	vector<long long> children = adjList[node];
	long long numChild = children.size();
	if(numChild==0 || (numChild==1 && children[0]==parent)){
		dp[node][0] = 1;
		dp[node][1] = 1;
		return;
	}
	long long temp1 = 1;
	long long temp2 = 1;
	for(long long child: children){
		if(child != parent){
			dfs(child, node);
			temp1 = ((temp1 % mod)*((dp[child][0] + dp[child][1]) % mod)) % mod;
			temp2 = (temp2*dp[child][0]) % mod;
		}
	}
	dp[node][0] = temp1;
	dp[node][1] = temp2;
}

int main(){
	cin >> N;
	long long x, y;
	for(long long i=1; i<N; i++){
		cin >> x >> y;
		x = x-1;
		y = y-1;
		adjList[x].push_back(y);
		adjList[y].push_back(x);
	}

	long long root = 0;
	dfs(root, -1);
	cout << (dp[root][0]+dp[root][1]) % mod << endl;
}










