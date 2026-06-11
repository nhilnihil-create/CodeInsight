#include<bits/stdc++.h>

using namespace std;
#define ll unsigned long long


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string A;
	string B;
	cin>>A;
	cin>>B;
	int n = A.length();
	int m = B.length();
	int dp[n + 1][m + 1];
	for (int i=0; i<=n; i++){
		for (int j=0; j<=m; j++){
			dp[i][j] = 0;
		}
	}
	for (int i=0; i<=n; i++){
		for (int j=0; j<=m; j++){
			if(i == 0 || j == 0)
				dp[i][j] = 0;
			else{
				if(A[i - 1] == B[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	int ans = dp[n][m];
	map<int,int> check;
	vector<char> res;
	for (int i=n; i>=1; i--){
		for (int j=m; j>=1; j--){
			if(A[i - 1] == B[j - 1] && dp[i][j] == ans &&check[i - 1] == 0){
				res.push_back(A[i - 1]);
				check[i - 1] ++;
				ans--;
			}
			if(ans == 0)	break;	
		}
	}
	for (int i=res.size()-1; i>=0; i--){
		cout<<res[i];
	}
}