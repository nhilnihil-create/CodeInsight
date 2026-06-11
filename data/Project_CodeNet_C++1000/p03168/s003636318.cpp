#include"bits/stdc++.h"
#define ll long long
#define inf 100005
#define mod 1000000007
using namespace  std;

vector<vector<ll>>g(inf);
vector<ll>indgree(inf);
vector<ll>dist(inf);
bool visted[inf];



int main(){
	ll n;
	cin>>n;

	vector<double>p(n+1);

	for(ll i=1;i<=n;i++){
		cin>>p[i];
	}

	vector<vector<double>>dp(n+1,vector<double>(n+1));
	dp[0][0]=1;
	for(ll i=1;i<=n;i++){
		for(ll j=0;j<=n;j++){
			if(j==0){
				dp[i][j] = (1-p[i])*dp[i-1][j];
			}else{
				dp[i][j] = (p[i])*dp[i-1][j-1]+(1-p[i])*dp[i-1][j];
			}
		}
	}

	double res = 0;

	for(ll i=n/2+1;i<=n;i++){
		res+=dp[n][i];
	}

	
	printf("%.10lf\n",res);
	return 0;
}