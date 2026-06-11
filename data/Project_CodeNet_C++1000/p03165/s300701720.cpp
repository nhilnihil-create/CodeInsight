#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main() {
	string a,b;
	cin>>a>>b;
	int n = a.length(),m=b.length(),i,j;
	int dp[n+1][m+1];
	memset(dp,0,sizeof(dp));
	
	for(i=1;i<=n;i++){
	    for(j=1;j<=m;j++){
	        if(a[i-1] == b[j-1])
	            dp[i][j] = 1+dp[i-1][j-1];
	        else
	            dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
	    }
	}
	string res = "";
	i=n,j=m;
	while(i>0 && j>0){
	    if(a[i-1] == b[j-1]){
	        res.push_back(a[i-1]);
	        i--;
	        j--;
	    }
	    else if(dp[i][j] == dp[i-1][j])
	        i--;
	    else
	        j--;
	}
	reverse(res.begin(),res.end());
	cout<<res<<endl;
	return 0;
}