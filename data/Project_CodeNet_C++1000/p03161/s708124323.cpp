#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <queue>
#include <stack>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

void yes(){
	cout<<"YES";
	exit(0);
}

void no(){
	cout<<"NO";
	exit(0);
}

const int sz = 5e5 + 7; 
// int arr;
long long int arr[sz];
int dp[sz];
// int d1[size];
// int dn[size];
pair<int, long long int> dl[sz], dr[sz];
// int special_nodes[size];
// bool visited[size];
// vector<int> graph[size];

// void bfs(int u, int *arr) {
// 	queue<int> q;
// 	memset(visited, 0, sizeof(visited));
// 	q.push(u);
// 	visited[u] = true;
// 	while(!q.empty()) {
// 		int t = q.front();
// 		q.pop();
// 		for(int x: graph[t]){
// 			if(!visited[x]) {
// 				visited[x] = true;
// 				arr[x] = arr[t] + 1;
// 				q.push(x);
// 			}
// 		}
// 	}
// }
int k;

long long int solve(int i, int n) {
	if(i > n) return INT_MAX;
	if(i== n) return 0;
	if(dp[i] != -1) return dp[i];
	long long int ans = INT_MAX;
	for(int x=1;x<=k;x++){
		if(x+i <=n ) ans = min(ans, solve(x+i, n) + abs(arr[i+x] - arr[i]));
	}
	dp[i] = ans;
	return ans;
}

int main() {
	int n;
	cin>>n>>k;
	for(int x=1;x<=n;x++){
		cin>>arr[x];
	}
	for(int x=0;x<sz;x++) dp[x] = -1;
	// dp[]	
	cout<<solve(1, n);
}
