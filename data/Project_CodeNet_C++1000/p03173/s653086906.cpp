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
const ll inf = 1e18+5;

vector<int> a;
ll dp[401][401];


ll s(int l, int r){
  
  ll sum = 0;
  for(int i=l; i<=r; i++){
    sum += a[i];
  }

  return sum;
}

int main(){
    // ******* START HERE ******
    
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
      int x;
      cin>>x;
      a.pb(x);
    }
    
    memset(dp, 0, sizeof(dp));
    
    for(int l = n-1; l>=0; l--){
       for(int r = l; r<n; r++){
          if(l==r)
            dp[l][r] = 0;
          else{
            dp[l][r] = inf;
            for(int i=l; i<=r-1; i++){
              dp[l][r] = min(dp[l][r], dp[l][i] + dp[i+1][r] + s(l,r) );
            }
          }
       }
    }

    cout<<dp[0][n-1]<<endl;

    // ***** END HERE ***** 
    return 0;
}