#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long int i=0;i<n;i++)
#define foi(i,a,n) for(long long int i=a;i<n;i++)
#define el "\n"

const int INF = 2e9+5;
const int MAX = 1e5+5;
const int mod = 1e9+7;
using ll = long long int;

void solve(){
	int n;cin>>n;
  	vector<double> dp(n+1);
  	dp[0]=1;
  	rep(i,n){
    	double p;cin>>p;
      	for(int j=i+1;j>=0;j--){
        	dp[j]=(j==0?0:dp[j-1])*p+dp[j]*(1-p);
        }
    }
  	double ans=0;
  	
  	foi(i,(n/2)+1,n+1) ans+=dp[i];
  	cout<<fixed<<setprecision(9)<<ans;
}

int main(){
  solve();
  return 0;
}