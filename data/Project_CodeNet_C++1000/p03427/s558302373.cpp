#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  int dp[2] ={0,INT_MIN};
  rep(i,s.size()){
    // cout << dp[0] <<" " << dp[1] << endl;
    int v = s[i]-'0';   
    // cout << v << endl; 
    int ndp[2];
    ndp[0] = dp[0] + v;
    ndp[1] = dp[1]+9;
    if(v!=0) {
      ndp[1] = max(ndp[1],dp[0]+v-1);
      // cout << ndp[1] << endl;
    }
    swap(ndp,dp);
  }
  cout << max(dp[0],dp[1]) << endl;
  
  return 0;
    

}
