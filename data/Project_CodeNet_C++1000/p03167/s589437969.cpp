#include <iostream>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int n,m;
	cin>>n>>m;
	vector<vector<int>> dp(n, vector<int>(m, 0));
	vector<vector<char>> grid(n, vector<char>(m, '.'));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char inp;
			cin>>inp;
			if(inp=='#')grid[i][j] = '#';
		}
	}
	dp[n-1][m-1] = 0;
	for(int i=n-1;i>=0;i--){
		for(int j=m-1;j>=0;j--){
			if(j==m-1 && i==n-1)continue;
			else if(j==m-1){
				if(grid[i][j]!='#'){
					if(i==n-2 || dp[i+1][j])dp[i][j] = 1;
				}
			}
			else if(i == n-1){
				if(grid[i][j]!='#'){
					if(j==m-2 || dp[i][j+1])dp[i][j] = 1;
				}
			}
			else{
				if(grid[i][j]!='#'){
					dp[i][j] = (dp[i+1][j] % int(1e9+7) + dp[i][j+1] % int(1e9 + 7)) % int(1e9 + 7);
				}
			}
		}
	}
	cout<<dp[0][0];
	return 0;
}