#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define mx INT_MAX
#define mn INT_MIN
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define itr set<int> :: iterator
const int mod = 1e9+7;

vector<ll> a;
ll dp[101][100001];

int main(){

    // ******* START HERE ******
    
    int n,k;
    cin>>n>>k;

    a.clear();
    for(int i=0; i<n; i++){
      ll x;
      cin>>x;
      a.pb(x);
    }
    
    dp[0][0] = 1;
    for(int i=1; i<=k; i++)
      dp[0][i] = 0;

    for(int i=1; i<=n; i++){
       vector<ll> sum(k+1);
       sum[0] = dp[i-1][0];

       for(int j=1; j<=k; j++)
          sum[j] = ( sum[j-1] + dp[i-1][j] )%mod;

       for(int j=0; j<=k; j++){
          if( j <= a[i-1] )
            dp[i][j] = sum[j];
          else{
            dp[i][j] = ( sum[j]-sum[j-a[i-1]-1]+mod )%mod;
          }
       }
       sum.clear();
    }
    
    cout<<dp[n][k]<<endl;
    // ***** END HERE ***** 
    return 0;
}