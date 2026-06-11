#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=105;
ll a[N],inf=1e9+7;
int main() {
	int n,k;
  	cin>>n>>k;
  	for(int i=0;i<n;i++) {cin>>a[i];}
  	ll dp[k+1]={0};
  	dp[0]=1;
  	for(int i=0;i<n;i++) {
    	ll x[k+1];
      	x[0]=dp[0];
      	for(int j=1;j<=k;j++) {x[j]=(x[j-1]+dp[j])%inf;}
      	for(int j=0;j<=k;j++) {
        	if(j<=a[i]) {dp[j]=x[j];}
          	else {
            	dp[j]=(x[j]-x[j-a[i]-1]+inf)%inf;
            }
        }
    }
  cout<<dp[k]<<endl;
return 0;
}
