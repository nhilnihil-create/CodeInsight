#include "bits/stdc++.h"
using namespace std;

#define ff first
#define ss second
#define pb push_back
#define int long long


signed main(){

int mod=1000000007;

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
#else
// online submission
#endif

int r,c;
cin >> r >> c;

char grid[r][c];

for(int i=0;i<r;i++){
	for(int j=0;j<c;j++){
		cin >> grid[i][j];
	}
}


int dp[r][c];

memset(dp, 0, sizeof(dp)); 





int i=0;

while(i<r && grid[i][0]!='#'){
	dp[i][0]=1;
	i++;
}


i=0;
while(i<c && grid[0][i]!='#'){
	dp[0][i]=1;
	i++;
}



for(int i=1;i<r;i++){
	for(int j=1;j<c;j++){
		if(grid[i][j]=='#')
		continue ;
		
		dp[i][j]=( dp[i-1][j]+dp[i][j-1] )%mod ;
	}
}

cout<<dp[r-1][c-1];	

	return 0;
    
}


