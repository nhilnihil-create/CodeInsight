#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
using namespace std;
#define int long long
#define fr(i,n) for (int i = 0; i < n; i++)
#define fro(i,m,n) for (int i = m; i < n; i++)
#define pb push_back
#define iter ::iterator
#define fi first
#define se second


void io(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
}

void solve(){
  //io();
  int n;
  cin>>n;
  int a[n][3];
  fr(i,n){
    cin>>a[i][0]>>a[i][1]>>a[i][2];
  }
  int dp[n+1][3];
  fr(i,3)dp[0][i]=0;
  fro(i,1,n+1){
    fr(j,3){
      dp[i][j]=a[i-1][j]+max(dp[i-1][(j+1)%3],dp[i-1][(j+2)%3]);
    }
  }
  std::cout << max(max(dp[n][0],dp[n][1]),dp[n][2]) << '\n';
}



int32_t main(){
  std::ios::sync_with_stdio(false);
  solve();
  return 0;
}
