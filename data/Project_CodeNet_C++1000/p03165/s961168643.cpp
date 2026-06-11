#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
	string str1, str2;
	cin >> str1 >> str2;
	int len1 = str1.size();
	int len2 = str2.size();

	int dp[len1+1][len2+1];
	memset(dp, 0, sizeof(dp));

	for(int i=1;i<=len1;i++){
		for(int j=1;j<=len2;j++){
			if(str1[i-1] == str2[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	string ans = "";
	int i=len1;
	int j=len2;
	while(i!=0 && j!=0){
		if(dp[i][j] == dp[i-1][j])
			i--;
		else if(dp[i][j] == dp[i][j-1])
			j--;
		else {
			ans = str1[i-1] + ans;
			i--;
			j--;

		}

	}
	cout << ans << endl;
	return 0;

}
