#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<vector<int>> inp(n, vector<int>(3));
  for(auto &x: inp)
	for(auto &y: x)
		cin>>y;
  vector<vector<int>> dp(n + 1, vector<int>(3));
  for(int i{1}; i <= n; ++i){
    for(int j{0}; j <= 2; ++j){
    	dp[i][j] = max(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + inp[i - 1][j];
    }
  }
  cout<<max({dp[n][0], dp[n][1], dp[n][2]});
}
