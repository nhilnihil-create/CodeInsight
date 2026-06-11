#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int h, w;
	cin >> h >> w;
	int dp[h][w], i, j;
	char grid[h][w];
	for(i = 0; i < h; i++){
	    for(j = 0; j < w; j++){
	        cin >> grid[i][j];
	        dp[i][j] = 0;
	    }
	}
	dp[0][0] = 1;
	for(i = 1; i < h; i++)
    {
	    if(grid[i-1][0] == '#' || grid[i][0] == '#' || dp[i-1][0] == 0)
	        dp[i][0] = 0;
	    else
	        dp[i][0] = 1;
	}
	for(j = 1; j < w; j++)
    {
	    if(grid[0][j-1] == '#' || grid[0][j] == '#' || dp[0][j-1] == 0)
	        dp[0][j] = 0;
	    else
	        dp[0][j] = 1;
    }
	for(i = 1; i < h; i++)
	{
	    for(j = 1; j < w; j++)
	    {
	        if(grid[i][j] != '#')
	        {
	            if(grid[i][j-1] != '#')
    	            dp[i][j] = (dp[i][j] + dp[i][j-1]) % 1000000007;
    	        if(grid[i-1][j] != '#')
    	            dp[i][j] = (dp[i][j] + dp[i-1][j]) % 1000000007;
	        }
	    }
	}
	cout << dp[h-1][w-1] << endl;

	return 0;
}
