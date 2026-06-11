#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
vector<pair<int64_t,int64_t>>prime_factorize(int64_t x){
  vector<pair<int64_t,int64_t>>p;
  for(int64_t i=2;i*i<=x;i++){
    int cnt=0;
    if(x%i==0){
    while(x%i==0){cnt++;x/=i;}
    p.push_back(make_pair(i,cnt));
    }
  }
  if(x!=1){p.push_back(make_pair(x,1));}
  return p; 
}
int dp[100010];
int main() {
  int N;
  cin>>N;
  dp[0]=0;
  for(int n=1;n<=100000;n++){
    dp[n]=999999;
    int power=1;
    while(power<=n){
      dp[n]=min(dp[n],dp[n-power]+1);
      power*=6;
    }
    power=1;
    while(power<=n){
      dp[n]=min(dp[n],dp[n-power]+1);
      power*=9;
    }
  }
  cout<<dp[N]<<endl;
  return 0;
}