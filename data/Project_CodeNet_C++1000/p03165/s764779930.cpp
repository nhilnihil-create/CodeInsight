#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int main() {
	string s, t;
	cin >> s;
	cin >> t;
	int m = s.size();
	int n = t.size();
	int cols = m+1, rows = n+1;
	int dp[n+1][m+1];
	for(int i = 0; i < rows; i++){
		dp[i][0] = 0;
	}
	for(int i = 0; i < cols; i++){
		dp[0][i] = 0;
	}
	
	string ans = "";
	for(int i = 1; i < rows; i++){
		for(int j = 1; j < cols; j++){
			if (s[j-1] == t[i-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else{
				if (dp[i-1][j] > dp[i][j-1]){
					dp[i][j] = dp[i-1][j];
				}
				else{
					dp[i][j] = dp[i][j-1];
				}
			}
		}
	}
	//cout << "\n" << rows << " " << cols << "\n\n";
	/*
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++)
		    cout << dp[i][j] << " ";
		cout << "\n";
	}
	*/
	int i = rows - 1, j = cols - 1;
	while(i > 0 && j > 0){
		if (s[j-1] == t[i-1]){
			ans = s[j-1] + ans;
			i--;
			j--;
		}
		else{
			if (dp[i-1][j] > dp[i][j-1]){
				i = i-1;
			}
			else{
				j = j-1;
			}
		}
		//cout << "i, j, ans = " << i << " " << j << " " << ans << "\n";
	}
	cout << ans;
	
	return 0;
}