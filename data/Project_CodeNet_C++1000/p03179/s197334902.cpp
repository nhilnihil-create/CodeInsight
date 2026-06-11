#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int size=1e5;
const int inf=1e9;
int main(){
	int N; string s; cin>>N>>s;
	long dp[N][N] = {}; dp[0][0] = 1;
	rep(i,1,N){
		if(s[i-1] == '<'){
			for(int j = 1; j <= i; j++) (dp[i][j] += dp[i][j-1] + dp[i-1][j-1] % mod) %= mod;
		}else{
			for(int j = i-1; j >= 0; j--) (dp[i][j] += dp[i][j+1] + dp[i-1][j] % mod) %= mod;
		}
	}
	long ans = 0;
	rep(i,0,N) (ans += dp[N-1][i]) %= mod;
	cout<<ans<<endl;
}