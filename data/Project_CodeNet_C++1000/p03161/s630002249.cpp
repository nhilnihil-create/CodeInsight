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
  int n,k;
  cin>>n>>k;
  int a[n];
  fr(i,n){
    cin>>a[i];
  }
  int dp[n+1]={0};
  int mi;
  //std::cout << k << '\n';
  fro(i,1,n){
    mi=INT_MAX;
    for(int j=1;j<=k&&((i-j)>=0);j++){
      mi=min(mi,dp[i-j]+abs(a[i]-a[i-j]));
      //std::cout <<j << '\n';
    }
    dp[i]=mi;
  }
  std::cout << dp[n-1] << '\n';
}



int32_t main(){
  std::ios::sync_with_stdio(false);
  solve();
  return 0;
}
