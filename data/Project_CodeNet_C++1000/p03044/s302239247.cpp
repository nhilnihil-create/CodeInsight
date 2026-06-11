#include<bits/stdc++.h>
//#include<iostream>
 
using namespace std;
 
typedef long long ll;
 
const int N = 200005;
 
int n;
vector<pair<int,int> > adj[N];

ll dst[N];

void dfs(int x,int p){
	for(auto t:adj[x]){
		int y = t.first,v = t.second;
		if(y == p)continue;
		dst[y] = dst[x] + v;
		dfs(y,x);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		adj[x].push_back({y,z});
		adj[y].push_back({x,z});
	}
	
	dst[1] = 0;
	
	dfs(1,1);
	
	for(int i=1;i<=n;i++){
		cout<<(dst[i]%2)<<endl;
	}
	
	return 0;
}
