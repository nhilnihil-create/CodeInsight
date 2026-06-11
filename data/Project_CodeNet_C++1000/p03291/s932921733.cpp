#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)

const ll mod = 1e9+7;
const ll INF = -1*((1LL<<63)+1);
const int inf = -1*((1<<31)+1);

using namespace std;


ll dp[100005][4];
int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string S;
	cin >> S;
	int N = S.size();
	for(int i = N;i>=0;i--){
		for(int j=3;j>=0;j--){
			if(i==N){
				dp[i][j] = (j==3 ? 1:0);
			}else{
				dp[i][j] = dp[i+1][j] * (S[i]=='?'? 3LL :1LL);
				if(j<3 && (S[i] == '?' || S[i] == "ABC"[j])){
					dp[i][j] += dp[i+1][j+1];
				}
			}
			dp[i][j] %= mod;
		}
	}
	cout << dp[0][0] << endl;
}