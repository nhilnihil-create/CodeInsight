#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n;
  	cin>>n;
  	vector<vector<int>> arr(n, vector<int>(3));
  	for(int i = 0;i<n;i++){
      cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }
  	vector<vector<int>> dp(n, vector<int>(3));
	dp[0][0] = arr[0][0];
  	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][2];
  	
  	for(int i=1;i<n;i++){
    	for(int j=0;j<3;j++){
        	for(int k =0;k<3;k++){
            	if(j==k) continue;
                 dp[i][j] = max(dp[i][j], dp[i-1][k] + arr[i][j]);
            }
        }
    }
  	int ans = -1;
    for(int j=0;j<3;j++){
    	ans = max(ans, dp[n-1][j]);
    }
	cout<<ans<<endl;
}
	