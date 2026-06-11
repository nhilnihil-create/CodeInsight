#include<bits/stdc++.h>
using namespace std;

long long int fun(int n,vector<long long int> &a,vector<long long int> &b,vector<long long int> &c,vector<vector<long long int>> &dp,int k){
    if(n<0) return 0;
    if(dp[n][k]!=-1) return dp[n][k];
    int ans=0;
    int v[2]={-1};
    if(k==0){
        ans = a[n];
        v[0]=1;
        v[1]=2;
    }
    if(k==1){
        ans = b[n];
        v[0]=0;
        v[1]=2;
    }
    if(k==2){
        ans = c[n];
        v[0]=1;
        v[1]=0;
    }
    dp[n][k] = ans+max(fun(n-1,a,b,c,dp,v[0]),fun(n-1,a,b,c,dp,v[1]));
    return dp[n][k];
}
int main(){
	long long int n,x,k,y;
	cin>>n;
	vector<long long int> a,b,c;
	vector<vector<long long int>> dp(n+1,vector<long long int>(3,-1));
	for(int i=0;i<n;i++){
		cin>>x>>y>>k;
		a.push_back(x);
		b.push_back(y);
		c.push_back(k);
	}
	long long int ans = fun(n-1,a,b,c,dp,0);
	ans = max(ans,fun(n-1,a,b,c,dp,1));
	ans = max(ans,fun(n-1,a,b,c,dp,2));
	cout<<ans<<endl;
}