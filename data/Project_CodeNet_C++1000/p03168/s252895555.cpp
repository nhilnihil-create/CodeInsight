#include<bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mod 1000000007
#define test ll t; cin>>t; while(t--)
typedef long long int ll;
int main() {
    FIO;
    //test
    {
       ll n;
       cin>>n;
       vector<double>a(n);
       for(int i=0;i<n;i++){
           cin>>a[i];
       }
       // Taken the input
       vector<vector<double>>dp(n+1,vector<double>(n+1,0));
       dp[0][0]=1;
       for(int i=0;i<n;i++){
           dp[i+1][0]=(dp[i][0]*(1-a[i]));
           for(int j=1;j<=n;j++){
               dp[i+1][j]+=(dp[i][j]*(1-a[i]));
               dp[i+1][j]+=(dp[i][j-1]*a[i]);
           }
       }
       n++;
       double ans=0;
       for(int i=n/2;i<n;i++){
           ans+=dp[n-1][i];
       }
       cout<<fixed<<setprecision(10)<<ans<<endl;
    }
	return 0;
}
