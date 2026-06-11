
#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<climits>

using namespace std;

#define lld long long int
#define MOD 1000000007
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);	cout.tie(0);

/* 											CODE:-									*/
														


void IMPLEMENT_CODE(){
	
	char s[3001], t[3001];
	cin>>s>>t;

	int l1 = strlen(s);
	int l2 = strlen(t);

	int dp[l1+1][l2+1];

	int l = 0;

	for(int i=0; i<=l1; i++){
		for(int j=0; j<=l2; j++){
			if(i==0 || j==0)
				dp[i][j] = 0;
			else if(s[i-1] == t[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	l = dp[l1][l2];
	//cout<<l<<endl;

	char ans[l];
	ans[l] = '\0';
	int i=l1, j=l2;
	while(i>0 && j>0){
		if(s[i-1]==t[j-1]){
			ans[--l] = s[i-1];
			i--;
			j--;
		}
		else if(dp[i-1][j] > dp[i][j-1])
			i--;
		else
			j--;
	}
	cout<<ans<<endl;
}



int main(){
	
	FASTIO;

	IMPLEMENT_CODE();

	return 0;

}
