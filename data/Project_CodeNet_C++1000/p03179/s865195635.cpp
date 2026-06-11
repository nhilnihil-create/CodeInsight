#include <bits/stdc++.h>
using namespace std;
#define fi first
#define endl "\n"
#define se second
#define ll long long
#define inf 0x3f3f3f3f
#define fast    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N = 3e3+5;
const ll mod =   1e9+7;
ll n;string s;
ll dp[N][N],sum[N][N];
int main()
{  fast
 cin>>n;
 cin>>s;
dp[0][0]=1;
for(int i=1;i<=n;i++)
sum[0][i]=1;
for(int i=0;i<n-1;i++){
	for(int j=0;j<=i+1;j++){
		if(s[i]=='>'){
			dp[i+1][j]=((sum[i][i+1]-sum[i][j])%mod+mod)%mod;
		}
		else{
			dp[i+1][j]=sum[i][j];
		}
		sum[i+1][j+1]=(sum[i+1][j]+dp[i+1][j])%mod;
	}
}
cout<<sum[n-1][n];
}