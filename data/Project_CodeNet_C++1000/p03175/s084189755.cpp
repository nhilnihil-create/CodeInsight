#include <bits/stdc++.h>
using namespace std;

const int M=1e9+7;

void dfs(vector<pair<int,int>>&dp,vector<int>*v,int p,vector<int>&vis){
	//cout<<p<<endl;
	if(v[p].size()==1){
		dp[p].first=1;
		dp[p].second=1;
	//	cout<<p<<endl;
	}else{
		long long int pro1=1,pro2=1;
		for(int i=0;i<v[p].size();i++){
			int x=v[p][i];
			if(vis[x])continue;
			vis[x]=1;
			dfs(dp,v,x,vis);
			pro1*=dp[x].first;
			pro2*=(dp[x].first+dp[x].second);
			pro1%=M;
			pro2%=M;
		}
		
		
		
		dp[p].first=pro2;
		dp[p].second=pro1;
	}
	
}

int main() {
	// your code goes here
	int n;cin>>n;
	vector<int>v[n];
	for(int i=0;i<n-1;i++){
		int x,y;cin>>x>>y;
		x--;y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	
	int pos=0;
	for(int i=0;i<n;i++){
		if(v[i].size()!=1){
			pos=i;break;
		}
	}
	vector<pair<int,int>>dp(n);
	vector<int>vis(n,0);
	vis[pos]=1;

	dfs(dp,v,pos,vis);
//	cout<<pos<<endl;
	/*
	for(int i=0;i<n;i++){
		cout<<i<<" "<<dp[i].first<<" "<<dp[i].second<<endl;
	}*/
	
	if(n==2){
		cout<<3<<endl;
	}
	else{
		cout<<(dp[pos].first+dp[pos].second)%M<<endl;
	}
	return 0;
}