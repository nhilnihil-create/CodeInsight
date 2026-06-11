#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)

const ll mod = 1e9+7;
const ll INF = -1*((1LL<<63)+1);
const int inf = -1*((1<<31)+1);

using namespace std;
ll dp[100005][4];
// dp[i+1][0] := i文字目まで見た時にABCとの照合をスタートしていないものの個数
// dp[i+1][1] := i文字目まで見た時にABCとの照合においてAまでは照合させたようなものの個数
// dp[i+1][2] := i文字目まで見た時にABCとの照合においてBまでは照合させたようなものの個数
// dp[i+1][3] := i文字目まで見た時にABCとの照合においてCまでは照合させたようなものの個数

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string S;
	cin >> S;
	dp[0][0] = 1;
	
	for(int i=0;i<S.size();i++){
		for(int j=0;j<4;j++){
			if(S[i] == '?') dp[i+1][j] = dp[i][j] * 3;
			else dp[i+1][j] += dp[i][j];
			dp[i+1][j] %= mod;
		}
		if(S[i] =='A' || S[i] == '?')dp[i+1][1] += dp[i][0];
		if(S[i] =='B' || S[i] == '?')dp[i+1][2] += dp[i][1];
		if(S[i] =='C' || S[i] == '?')dp[i+1][3] += dp[i][2];
	}
	cout << dp[S.size()][3]%mod << endl;
}
