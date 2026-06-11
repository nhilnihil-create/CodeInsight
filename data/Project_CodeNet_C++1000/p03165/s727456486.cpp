#include<bits/stdc++.h>

using namespace std;

int main(){

	string s;
	string t;

	cin >> s >> t;


	vector<vector<int>> DP(s.size(),vector<int>(t.size(),0));

	DP[0][0] = s[0]==t[0];

	for(int j=1;j<t.size();j++){

		if(s[0]==t[j]){
			DP[0][j] = 1;
		}else{
			DP[0][j] = DP[0][j-1];
		}

	}

	//init
	for(int i=1;i<s.size();i++){
		if(t[0]==s[i]){
			DP[i][0] = 1;
		}else{
			DP[i][0] = DP[i-1][0];
		}
	}

	//bottom up approach
	for(int i=1;i<s.size();i++){
		for(int j=1;j<t.size();j++){

			if(s[i]==t[j]){
				DP[i][j] = max(DP[i-1][j-1]+1,max(DP[i-1][j],DP[i][j-1]));
			}else{
				DP[i][j] = max(DP[i-1][j],DP[i][j-1]);
			}

		}
	}

	//extract the string from DP
	
	string ans;

	int i=s.size()-1;
	int j=t.size()-1;


	while((i>0)&&(j>0)){

			if(DP[i][j]==DP[i][j-1]){
				j--;
			}else if(DP[i][j]==DP[i-1][j]){
				i--;
			}else{
				ans = s[i]+ ans;
				i--;
				j--;
			}

	}

	if((i==0)&&(DP[0][j]==1)){
		
		while((j>=0)&&(DP[0][j]==1)){
			j--;
		}
			ans = t[j+1] + ans;
	}


	if((j==0)&&(DP[i][0]==1)){

		while((i>=0)&&(DP[i][0]==1)){
			i--;
		}
			ans = s[i+1] + ans;
	}


	cout << ans << endl;


	return 0;
}