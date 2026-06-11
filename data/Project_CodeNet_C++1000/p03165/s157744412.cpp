#include<iostream>
#include<vector>

using namespace std;

int main(){
	string s1,s2;
	cin >> s1 >> s2;
	int n1=s1.length();
	int n2=s2.length();
	
	vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
	
	for(int i=1;i<=n1;i++){
		for(int j=1;j<=n2;j++){
			if(s1[i-1]==s2[j-1])
				dp[i][j]=1+dp[i-1][j-1];
			else 
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	
	int len=dp[n1][n2];
	int i=n1,j=n2;
	string res="";
	while(len > 0){
		if(dp[i-1][j-1]==dp[i-1][j] && dp[i-1][j]==dp[i][j-1]){
			if(dp[i][j] > dp[i-1][j-1]){
				len-=1;
				res=s1[i-1]+res;
				i-=1;
				j-=1;
			}
			else
				j-=1;
		}
		else{
			if(dp[i-1][j] == dp[i][j])
				i-=1;
			else 
				j-=1;
		}
	}
	cout<<res<<"\n";
	return 0;
}