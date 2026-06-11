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
#define map_itr map<int,int> :: iterator
const int mod = 1e9+7;
int n;

vector<vector<int> > a(22, vector<int> (22));
int ALL_WOMEN;

int main(){
    // ******* START HERE ******
    
    cin>>n;
    ALL_WOMEN = (1<<n);
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
          cin>>a[i][j];
      }
    }
    
    vector<int> dp(ALL_WOMEN);

    dp[0] = 1;

    for(int mask=0; mask<ALL_WOMEN-1; mask++){
      int i = __builtin_popcount(mask);
       for(int j=0; j<n; j++){
          if(a[i][j]==1 && !(mask&(1<<j)) ){
            int m2 = mask^(1<<j);
            dp[m2] = (dp[m2] + dp[mask])%mod;
          }
       }
    }

    cout<<dp[ALL_WOMEN-1]<<endl;
    // ***** END HERE ***** 
    return 0;
}