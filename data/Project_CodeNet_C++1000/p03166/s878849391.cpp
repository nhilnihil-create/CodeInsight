#include<bits/stdc++.h>
using namespace std;
const int maxn = 100000+5;
int visits[100000+5];
int dp[100000+5];

void dfs(int node,vector<int> v[]){
	visits[node] = true;
	for(int i=0; i<v[node].size(); i++){
		if(!visits[v[node][i]]){
			dfs(v[node][i], v);
		}
		dp[node] = max(dp[node], dp[v[node][i]] + 1);
	}
}

int main(int argc, char const *argv[])
{
	int N, M;
	while(cin >> N >> M) {
		vector<int> v[100000+5];
		int big = 0;
		memset(dp, 0, sizeof(dp));
		for(int i=0; i<M; i++){
			int place1, place2;
			cin >> place1 >> place2;
 			v[place1].push_back(place2);
		}
		for(int i=1; i<=N; i++){
			if(!visits[i]){
				dfs(i, v);
			}
		}
		for(int i=1; i<=N; i++){
			big = max(big, dp[i]);
		}
		cout << big << endl;
	}
	return 0;
}