#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string lcs(vector<vector<int>> &dp, string &s1, string &s2){
	for(int i=1;i<=s1.size();i++){
		for(int j=1;j<=s2.size();j++){
			if(s1[i-1]==s2[j-1])dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	string result = "";
	int i = s1.size();
	int j = s2.size();
	while(i>0 && j>0){
		if(dp[i-1][j]==dp[i][j])i--;
		else if(dp[i][j]==dp[i][j-1])j--;
		else{
			result += s1[i-1];
			i--;
			j--;
		}
	}
	reverse(result.begin(), result.end());
	return result;
}

int main() {
	// your code goes here
	string s1;
	string s2;
	cin>>s1>>s2;
	vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
	cout<<lcs(dp, s1, s2)<<endl;
	return 0;
}