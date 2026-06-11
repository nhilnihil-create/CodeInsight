#include<bits/stdc++.h>
using namespace std;
const int M=(int)1e9+7;
int ad(int x,int y){
	if(y<0)
		y+=M;
	return (x+y)%M;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	vector<vector<int> > dp(n+1,vector<int> (n+1));
	dp[1][1]=1;
	for(int i=2;i<=n;i++){
		char c;
		cin>>c;
		if(c=='<')
			for(int j=1;j<=i;j++)
				dp[i][j]=ad(dp[i-1][j-1],dp[i][j-1]);
		else
			for(int j=1;j<=i;j++)
				dp[i][j]=ad(ad(dp[i-1][i-1],-dp[i-1][j-1]),dp[i][j-1]);		
	}
	cout<<dp[n][n]<<endl;
}