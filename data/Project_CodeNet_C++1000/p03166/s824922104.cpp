#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>graph[100005];
int dp[100005];
int f(int curr){
	int&ret = dp[curr];
	if(~ret) return ret;
	ret = 0;
	for(int i=0; i<graph[curr].size(); i++){
		int nexter = graph[curr][i];
		ret = max(ret,f(nexter)+1);
	}
	return ret;
}
int main(){
	memset(dp,-1,sizeof(dp));
	int m;
	cin>>n>>m;
	while(m--){
		int a,b;
		cin>>a>>b;
		graph[a].push_back(b);
	}
	int mx = 0;
	for(int i=1; i<=n; i++)	mx = max(mx,f(i));
	cout<<mx; 
}