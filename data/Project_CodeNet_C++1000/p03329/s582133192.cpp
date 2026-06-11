#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll mod= 1e9 + 7;



int main(){
  int n;
  cin >>n;
  int dp[100010];
  rep(i,100010)dp[i]=i;
  
  for(int i=1;i<=100000;i++){
    int p=1;
    while(p<=i){
      chmin(dp[i],dp[i-p]+1);
      p*=6;
    }
    int g=1;
    while(g<=i){
      chmin(dp[i],dp[i-g]+1);
      g*=9;
    }
  }

  cout << dp[n] << endl;
}