#include <iostream>

using namespace std;

int dp[5000][5000];


void lcs(string s1,string s2){
	
	for(int i=1;i<=s1.size();i++){
		for(int j=1;j<=s2.size();j++){
			if(s1[i-1]==s2[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
		}
	}

}

int main(){
	string s1;
	string s2;

	getline(cin,s1);
	getline(cin,s2);

	
	lcs(s1,s2);

	int i = s1.size();
	int j = s2.size();
	string s3 = "";                  	

	while(i > 0 && j > 0){
		if(s1[i-1] == s2[j-1]) {
			s3 = s1[i-1] + s3;
			i--;
			j--;
		}
		else if(dp[i-1][j] > dp[i][j-1]) i--;
		else j--;
		
	}

	cout << s3 << '\n';

	return 0;

}

