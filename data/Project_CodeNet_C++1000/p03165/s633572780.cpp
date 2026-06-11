#include <bits/stdc++.h>
using namespace std;

int main(){
	string s,t;
	cin >> s >> t;
	vector<vector<int>> dp(t.size()+1,vector<int>(s.size()+1));

	for(int i=1; i<=(int)t.size(); i++){
		for(int j=1; j<=(int)s.size(); j++){
			if(s[j-1] == t[i-1]){ dp[i][j] = dp[i-1][j-1]+1; }
			else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		}
	}
	string ans;
	int i = t.size(); 
	int j = s.size();
	int len = dp[i][j];
	while(len>0){
		if(s[j-1] == t[i-1]){
			ans.push_back(s[j-1]); len--;
			i--; j--;
		}else if(dp[i][j] == dp[i-1][j]){
			i--;
		}else{
			j--;
		}
	}
	reverse(ans.begin(),ans.end());
	cout << ans << endl;
	return 0;
}

