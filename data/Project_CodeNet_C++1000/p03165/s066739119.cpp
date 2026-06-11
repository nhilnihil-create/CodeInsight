#include <bits/stdc++.h>
using namespace std;
#define ll long long 


int main(){

	string s1, s2;
	cin >> s1 >> s2;
	int n = s1.length(), m = s2.length();

	int dp[n + 1][m + 1];

	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			if(!i || !j) dp[i][j] = 0;
			else if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	//for printing the subsequece :8(
	int l = dp[n][m];
	char temp[l + 1];
	temp[l] = '\0';
	int row = n, col = m;
	while(row && col){
		if(s1[row - 1] == s2[col - 1]){
			temp[--l] = s1[row - 1];
			row--;
			col--;
			
		}else if(dp[row - 1][col] > dp[row][col - 1]){
			row--;
		}else{
			col--;
		}
	}
	cout << temp; 

	
	
}
