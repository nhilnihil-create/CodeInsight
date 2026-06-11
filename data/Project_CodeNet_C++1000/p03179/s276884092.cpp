#include <iostream>
#include <cstring>
#include <string>
using namespace std;

#define rep(i,b,e) for(auto i=b;i<=e;i++)

const long long P = 1e9+7;

int main(){
	int n,L,R;
	string s;
	cin>>n>>s;
	long long dp[n+1][n+1];
	memset(dp,0,sizeof(dp));

	dp[1][1]=1;

	rep(i,2,n){

		rep(k,2,i){
			dp[i-1][k] = (dp[i-1][k]+dp[i-1][k-1])%P;
		}

		rep(j,1,i){
			long long rangeSum =0;
			if(s[i-2]=='<'){
				L=1,R=j-1;	
			}
			else{
				L=j,R=i-1;
			}

			if(L<=R)
				dp[i][j] = (dp[i][j]+ dp[i-1][R]-dp[i-1][L-1]+P)%P;
		}
	}

	long long ans = 0;
	rep(i,1,n)
		ans = (ans+dp[n][i])%P;
	cout<<ans<<endl;
}
