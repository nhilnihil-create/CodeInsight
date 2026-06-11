#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
bool pos[100000];
vector<int> x[100000];
int n,m,dp[100000];
void idi(int i){
	pos[i]=1;
	for(int j=0;j<x[i].size();j++){
		if(!pos[x[i][j]])
			idi(x[i][j]);
		dp[i]=max(dp[i],dp[x[i][j]]+1);
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)pos[i]=dp[i]=0;
	for(int i=0,a,b;i<m;i++){
		cin>>a>>b;
		--a;--b;
		x[a].pb(b);
	}
	for(int i=0;i<n;i++)
		if(!pos[i])
			idi(i);
	int ma=0;
	for(int i=0;i<n;i++)
		ma=max(ma,dp[i]);
	cout<<ma;
	return 0;
}