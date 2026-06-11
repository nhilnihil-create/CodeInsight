#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

vector<int> c={1,6,36,216,1296,
               7776,46656,9,81,729,
               6561,59049};

int main(){
  int n;
  cin>>n;
  vector<int> dp(n+1,100);
  dp[0]=0;
  rep(i,n){
    rep(j,12){
      if(i+c[j]>n) continue;
      dp[i+c[j]]=min(dp[i+c[j]],dp[i]+1);
    }
  }
  cout<<dp[n]<<endl;
}