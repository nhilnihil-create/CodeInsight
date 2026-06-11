#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const int inf=1<<30;

ll dp[3010][3010];

int main(){
  int n; cin >> n; n--;
  string s; cin >> s;
  rep(j,n+1) dp[0][j]=1;
  rep(i,n){
    if(s[i]=='<'){
      rep(j,n-i){
        if(j==0) dp[i+1][j]=dp[i][j];
        else dp[i+1][j]=dp[i+1][j-1]+dp[i][j];
        dp[i+1][j]%=mod;
      }
    }
    else{
      for(int j=n-i-1;j>=0;j--){
        dp[i+1][j]=dp[i+1][j+1]+dp[i][j+1];
        dp[i+1][j]%=mod;
      }
    }
  }
  cout << dp[n][0] << endl;
}