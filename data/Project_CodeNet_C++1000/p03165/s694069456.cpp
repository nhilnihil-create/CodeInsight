#include <bits/stdc++.h>

using namespace std;

int dp[3005][3005] , go[3005][3005];

int main(){
	string a , b , c = "";
	cin>>a>>b;
	for(int i = 1 ; i <= a.size() ; i++) for(int t = 1 ; t <= b.size() ; t++){
		if(a[i - 1] == b[t - 1]) dp[i][t] = dp[i - 1][t - 1] + 1 , go[i][t] = 2;
		else if(dp[i - 1][t] >= dp[i][t - 1]) dp[i][t] = dp[i - 1][t] , go[i][t] = 3;
		else dp[i][t] = dp[i][t - 1] , go[i][t] = 1;
	}
	// cout<<dp[a.size()][b.size()]<<endl;
	int x = a.size() , y = b.size();
	for(int i = 0 ; i < dp[a.size()][b.size()] ;){
		if(go[x][y] == 1) y--;
		else if(go[x][y] == 2){
			// cout<<a[x - 1]<<endl;
			c = a[x - 1] + c , x-- , y-- , i++;
		}
		else x--;
	}
	cout<<c<<endl;
}