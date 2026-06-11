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
  int a[n];
  fr(i,n){
    cin>>a[i];
  }
  int dp[n+1]={0};
  dp[1]=abs(a[1]-a[0]);
  fro(i,2,n){
    dp[i]=min(dp[i-1]+abs(a[i]-a[i-1]),dp[i-2]+abs(a[i]-a[i-2]));
  }
  std::cout << dp[n-1] << '\n';
}



int32_t main(){
  std::ios::sync_with_stdio(false);
  solve();
  return 0;
}
