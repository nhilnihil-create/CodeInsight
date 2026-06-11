#include<bits/stdc++.h>
#define mx 1000000007
#define ll long long int

using namespace std;

double dp[3000][3000]={0},one=1,two=2;
ll nn;

double solve(double p[],ll n,ll h){
	if(dp[n][h]>=0)
		return dp[n][h] ;
    if(n==0 && h<(nn+1)/2){
        return dp[n][h]=0;
    }
    if(n==0)
        return dp[n][h]=1;
    dp[n][h]= p[n]*solve(p,n-1,h+1)+ (1-p[n])*solve(p,n-1,h);
    return dp[n][h];
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	memset(dp,-1,sizeof(dp));
	cin>> nn;
	double p[nn+1];
	for(ll i=1;i<=nn;++i)
        cin>> p[i] ;
    double ans=solve(p,nn,0);
    cout<< fixed << setprecision(12) <<  ans ;
	return 0;
}
