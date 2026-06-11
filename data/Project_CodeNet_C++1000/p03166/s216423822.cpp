#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int maxValue = 1e5 + 5;

int dfs(int i , vector<int>g[] , int *maxNodes , int dist){
    if(g[i].size() == 0){
        maxNodes[i] = 1;
    }
    if(maxNodes[i] != 0) return maxNodes[i];
    for(int j : g[i]){
        maxNodes[i] = max(maxNodes[i] , dfs(j , g , maxNodes , dist) + 1);
    }
    return maxNodes[i];
}

int main(){
	int n , m;
	cin>>n>>m;
	vector<int>g[n + 1];
	for(int i = 0; i < m; i++){
	    int u , v;
	    cin>>u>>v;
	    g[u].push_back(v);
	}
	int maxNodes[n + 1];
	for(int i = 0; i <= n; i++){
	    maxNodes[i] = 0;
	}
	for(int i = 1; i <= n; i++){
	    if(maxNodes[i] == 0){
	        dfs(i , g , maxNodes , 0);
	    }
	}
	int ans = 0;
	for(int i = 0; i <= n; i++){
	    ans = max(ans , maxNodes[i]);
	}
	ans -= 1;
	cout<<ans;
}