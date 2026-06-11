#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<vector<int>> tree(n+1);
	for(int i=0;i<n-1;++i){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	queue<pair<int,int>> que;
	int l,r,dst;
	vector<int> cost(n+1,n*2);
	cost[l=1]=0;
	vector<bool> visited(n+1,false);
	que.push(make_pair(l,cost[l]));
	while(!que.empty()){
		pair<int,int> p=que.front();
		que.pop();
		visited[p.first]=true;
		if(cost[l]<p.second)l=p.first;
		for(auto c:tree[p.first]){
			if(!visited[c]){
				que.push(make_pair(c,p.second+1));
				cost[c]=min(cost[c],p.second+1);
			}
		}
	}
	cost = vector<int>(n+1,n*2);
	cost[r=l]=0;
	visited = vector<bool>(n+1,false);
	que.push(make_pair(l,cost[l]));
	while(!que.empty()){
		pair<int,int> p=que.front();
		que.pop();
		visited[p.first]=true;
		if(cost[r]<p.second)r=p.first;
		for(auto c:tree[p.first]){
			if(!visited[c]){
				que.push(make_pair(c,p.second+1));
				cost[c]=min(cost[c],p.second+1);
			}
		}
	}
	vector<bool> dp(cost[r]+1,0);
	dp[0]=true;
	dp[1]=false;
	for(int i=2;i<=cost[r];++i){
		dp[i]=!(dp[i-1]&&dp[i-2]);
	}
	cout<<(dp[cost[r]]?"First":"Second");
	return 0;
}