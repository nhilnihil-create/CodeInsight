#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
	int n, k;
	cin >> n >> k;
	
	int a[n]={};
	
	for(int i=0; i<n; i++)
		cin >> a[i];
	
	// we maintain state of game.
	// dp[0]-> loosing state
	// dp[1]-> winning state
	
	// each winning state there is atleast one branch that is lead to loosing state.
	
	int dp[k+1]={};
	memset(dp, 0, sizeof dp);
	
	// here dp[0]=0 menas if K=0 then first loose.
	// for each value of K think current is max val of K.
	// so transition with use each number.
	// and after choosing any number if oponent move to loossing state choose that number.
	
	dp[0]=0;
	for(int i=1; i<=k; i++){
		dp[i]=0;
		for(auto x : a){
			if(i>=x && dp[i-x]==0) {
				// after choose x ooponent is losing means dp[i-x]==0, so current choose this number.
				dp[i]=1;
				break;
			}
		}
	}
	
	if(dp[k]==1)
		cout << "First";
	else
		cout << "Second";
	
}

int main(){
	solve();
}
