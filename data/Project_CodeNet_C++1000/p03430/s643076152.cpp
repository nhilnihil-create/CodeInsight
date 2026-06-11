#include <bits/stdc++.h>
using namespace std;
int n, X, dp[301][301][301];
string s;
int main(){
    cin>>s>>X;n=s.size();    
    for (int i=0; i<n; i++)
		for (int x=0; x<=X; x++)dp[x][i][i]=1;
	for (int x=0; x<=X; x++)
		for (int k=1; k<n; k++)
			for (int l=0, r=k; l+k<n; l++, r=l+k)
				dp[x][l][r]=max(max(dp[x][l][r-1], dp[x][l+1][r]),
							dp[max(x-min(1,abs(s[l]-s[r])), 0)][l+1][r-1]+
							2*min(1, (min(1, x)+(1-min(1,abs(s[l]-s[r]))))));
    cout<<dp[X][0][n-1]<<endl;
    return 0;
}