#include <bits/stdc++.h>
using namespace std;
int n,dp[3005][3005],pref[3005][3005];
string s;

void add(int &a , int b){
	a += b;
	while(a >= 1000000007){
		a -= 1000000007;
	}
	while(a < 0){
		a += 1000000007;
	}
}

int main(){
	cin >> n >> s;
	for(int i = 0 ; i < n ; i += 1){
		dp[0][i] = 1;
	}
	for(int i = 0 ; i < n ; i += 1){
		if(s[i] == '<'){
			for(int k = 0 ; k <= n ; k += 1){
				if(k){
					add(pref[i][k],pref[i][k-1]);
				}
				add(dp[i][k],pref[i][k]);
				add(pref[i+1][0],dp[i][k]);
				add(pref[i+1][k],-dp[i][k]);
			}
		}else{
			for(int k = 0 ; k <= n ; k += 1){
				if(k){
					add(pref[i][k],pref[i][k-1]);
				}
				add(dp[i][k],pref[i][k]);
				add(pref[i+1][k],dp[i][k]);
				add(pref[i+1][n-i-1],-dp[i][k]);
			}
		}
	}
	cout << dp[n-1][0] << endl;
}