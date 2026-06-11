#include<bits/stdc++.h>
//#include<iostream>
 
using namespace std;
 
typedef long long ll;
 
const int N = 200005;
 
int n,m;

//vector<int> same[N],opp[N];
vector<int> adj[N];

int vstd[N];

void dfs(int x){
	vstd[x] = true;
	for(int y:adj[x]){
		if(!vstd[y])dfs(y);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		/*
		if(z & 1){
			opp[x].push_back(y);
			opp[y].push_back(x);
		}else{
			same[x].push_back(y);
			same[y].push_back(x);
		}
		*/
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	int ans = 0;
	for(int i=1;i<=n;i++){
		if(!vstd[i]){
			ans++;
			dfs(i);
		}
	}
	
	cout<<ans;
	
	return 0;
}
