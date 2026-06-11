#include "bits/stdc++.h"
using namespace std;

#define ff first
#define ss second
#define pb push_back
#define int long long

int mod=1e9+7;

vector<int> adj[100001];


pair<int,int> dfs(int s,int p){
	
	int s_black=1; int s_white=1;
	for(auto c: adj[s]){

		if(c!=p){

		pair<int,int>res= dfs(c,s) ;
		
		//s is black  
		s_black=s_black*res.second % mod;
		
		//s is white  
		s_white=s_white*((res.second+res.first)%mod) % mod;
		}
	}
	
	return {s_black,s_white} ;
	
}


signed main(){

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#else
// online submission
#endif


int n;
cin >> n;


for(int i=0;i<n-1;i++){
	int x,y;
	cin >> x >> y;
	adj[x].push_back(y);
	adj[y].push_back(x);
}

pair<int,int> res=dfs(1,-1);

cout<< (res.first+res.second)%mod;

    return 0;
}


