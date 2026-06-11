#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

using namespace std;

#define MAXN 400

ll dp[MAXN+1][MAXN+1];

int main(){
  int n;cin>>n;
  vector<ll>a(n);
  rep(i, n)cin>>a[i];

  vector<ll> suma(n+1, 0);
  rep(i, n)suma[i+1]+=suma[i]+a[i];

  rep1(l, n)rep(i, n){
    int j = i+l;
    if(i>=j || j>=n)continue;
    dp[i][j]=INF;

    ll sum = suma[j+1]-suma[i];
    for(int m=i; m<=j; m++){
      dp[i][j] = min(dp[i][j], dp[i][m]+dp[m+1][j]+sum);
    }
//    cout<<i<<' '<<j<<' '<<dp[i][j]<<' '<<sum<<endl;
  }

  cout<<dp[0][n-1]<<endl;

  return 0;
  rep(i, n+1){
    rep(j, n+1)cout<<dp[i][j]<<' ';
    cout<<endl;
  }

  return 0;
}