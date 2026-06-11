#include <bits/stdc++.h>
using namespace std;
 
const int mxN=1000, M=1e9+7;
int h, w, dp[mxN][mxN]={0};
string g[mxN];
 
bool ie(int i, int j) {
	return i>=0&&j>=0&&g[i][j]=='.';
}
 
int main()
 {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> h >> w;
	for(int i=0; i<h; ++i)
		cin >> g[i];

	dp[0][0]=1;
	for(int i=0; i<h; ++i) 
    {
		for(int j=0; j<w; ++j)
         {
			if(ie(i-1, j))
				dp[i][j]+=dp[i-1][j];
			if(ie(i, j-1))
				dp[i][j]+=dp[i][j-1];
			dp[i][j]%=M;
		}
	}
	cout << dp[h-1][w-1];
}
