#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll sum[401];
ll dp[401][401];
ll solve(vector<int> &slimes,int i,int j){
	if(i==j)
      return 0;
  	if(dp[i][j]!=-1)
      return dp[i][j];
  	ll cost=LONG_MAX;
  	for(int p=i;p<j;p++)
      cost=min(cost,solve(slimes,i,p)+solve(slimes,p+1,j)+sum[j]-sum[i-1]);
  	return dp[i][j]=cost;
}
int main(){
	int n;
  	cin>>n;
  	vector<int> slimes(n+1);
  	for(int i=1;i<=n;i++)
      	cin>>slimes[i];
  	memset(sum,0,sizeof sum);
  	memset(dp,-1,sizeof dp);
  	for(int i=1;i<=n;i++)
      sum[i]=sum[i-1]+slimes[i];
  	cout<<solve(slimes,1,n);
	}
