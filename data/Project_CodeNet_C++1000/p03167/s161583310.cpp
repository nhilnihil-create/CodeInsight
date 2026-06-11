#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int main(){
	int n,m;
	cin>>n>>m;
    vector<string> maze;
    for(int i=0;i<n;i++){
        string row;
        cin>>row;
        maze.push_back(row);
    }
	int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j]=0;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }else if(i==1 && j==1){
                dp[i][j]=1;
            }else if(maze[i-1][j-1]=='#'){
                dp[i][j]=0;
            }else{
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
            }
        }
    }
    cout<<dp[n][m];
	return 0;
}
