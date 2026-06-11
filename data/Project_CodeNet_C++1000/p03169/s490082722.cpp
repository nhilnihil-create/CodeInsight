#include<bits/stdc++.h>
using namespace std;
int N;
vector<vector<vector<double> > >dp;
double dfs(int a,int b,int c) {
	if(dp[a][b][c]>-1) return dp[a][b][c];
	if(a==0&&b==0&&c==0) return 0;
	dp[a][b][c]=(double)N/(a+b+c);
	if(a>0) dp[a][b][c]+=(double)a/(a+b+c)*dfs(a-1,b,c);
	if(b>0) dp[a][b][c]+=(double)b/(a+b+c)*dfs(a+1,b-1,c);
	if(c>0) dp[a][b][c]+=(double)c/(a+b+c)*dfs(a,b+1,c-1);
	return dp[a][b][c];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>N;
	vector<int>cnt(3);
	for(int i=0,a;i<N;i++) {
		cin>>a;
		cnt[a-1]++;
	}
	dp.resize(N+1,vector<vector<double> >(N+1,vector<double>(N+1,-1)));
	dp[0][0][0]=0;
	cout<<setprecision(15)<<dfs(cnt[0],cnt[1],cnt[2])<<'\n';
	return 0;
}
