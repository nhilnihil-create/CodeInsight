#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define ll long long
const int mod=1e9+7;

int main(){
#ifndef ONLINE_JUDGE
	freopen("C:\\Users\\User\\Documents\\input.txt","r",stdin);
#endif
	int T,i,j;
	int n,m;
	cin>>n>>m;
	string s[n];

	for(i=0;i<n;++i){
		cin>>s[i];
	}

	vector<vector<int> > dp(n,vector<int>(m) );

	dp[0][0]=1;
	int dr[]={0,1};
	int dc[]={1,0};

	for(i=0;i<n;i++){
		for(j=0;j<m;++j){
		    if(s[i][j]=='#') continue;
		    for(int k=0;k<2;k++){
		    	int r=dr[k]+i,c=dc[k]+j;
		    	if(r<n && c<m) dp[r][c]=(dp[r][c]+dp[i][j])%mod;
		    }
		}
	}
	printf("%d\n",dp[n-1][m-1]);


	return 0;
}