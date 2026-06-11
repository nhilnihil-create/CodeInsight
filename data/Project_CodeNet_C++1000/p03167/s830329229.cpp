#include <iostream>
#include <vector>
using namespace std;
int p = 1e9 + 7;
int main(){
	int h, w;
  	cin>>h>>w;
    vector<vector<char>> grid(h, vector<char>(w));
  	for(int i =0;i<h;i++){
    	for(int j =0;j<w;j++){
        	cin>>grid[i][j];
        }
    }
  	vector<vector<int>> dp(h, vector<int>(w));
	dp[0][0] = 1;
  	for(int i = 0;i<h;i++){
    	for(int j =0;j<w;j++){
         	if(grid[i][j] == '#') continue;
        	if(i>0 && grid[i-1][j]=='.')
          		dp[i][j] = (dp[i][j] + dp[i-1][j])%p; 
         	if(j>0 && grid[i][j-1]=='.')
				dp[i][j] = (dp[i][j] + dp[i][j-1])%p;
        }
    }
	cout<<dp[h-1][w-1]<<endl;
}