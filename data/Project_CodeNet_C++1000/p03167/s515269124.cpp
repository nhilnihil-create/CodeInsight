#include <bits/stdc++.h>
using namespace std;
#define F(i,a,n) for(int i=a;i<n;i++)
#define pb push_back
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef long long ll;
#define mod 1000000007
void dfs(vvi &v, vi &dp, vi &vis, int n,int i){
	vis[i]=1;
	F(j,0,v[i].size()){
		if(!vis[v[i][j]])dfs(v,dp,vis,n,v[i][j]);
	dp[i]=max(dp[i],dp[v[i][j]]+1);
}
}
int main()
{	
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int w=1;
	// cin>>w;
	while(w--){
		int h,w;
		cin>>h>>w;
		string s[h];
		F(i,0,h)cin>>s[i];
		int arr[h+1][w+1];
		F(i,0,h+1){
			arr[i][0]=0;
		}
		F(i,0,w+1)arr[0][i]=0;
		arr[1][1]=1;
		F(i,1,h+1){
			F(j,1,w+1){
				if(i==1&&j==1)continue;
				if(s[i-1][j-1]=='#'){
					arr[i][j]=0;
				}
				else {
					arr[i][j]=(arr[i-1][j]%mod+arr[i][j-1]%mod)%mod;
				}
			}
		}
		cout<<arr[h][w];
	}
}