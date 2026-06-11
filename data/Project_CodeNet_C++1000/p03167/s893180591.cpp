#include<bits/stdc++.h>
using namespace std;
int moder = 1000000007;
int h,w;
int grid[1005][1005];
int dp[1005][1005];
int f(int y,int x){
	int&ret = dp[y][x];
	if(~ret) return ret;
	ret = 0;
	if(y<h && grid[y+1][x]==0) ret+=f(y+1,x);
	ret%=moder;
	if(x<w && grid[y][x+1]==0) ret+=f(y,x+1);
	ret%=moder;
	return ret; 
}
int main(){
	cin>>h>>w;
	for(int i=1; i<=h; i++){
		string s;
		cin>>s;
		for(int j=0; s[j]; j++){
			if(s[j]=='#') grid[i][j+1] = 1;
		}
	}
	memset(dp,-1,sizeof(dp));
	dp[h][w] = 1;
	cout<<f(1,1);
}