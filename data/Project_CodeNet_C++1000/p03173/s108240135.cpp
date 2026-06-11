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

#define MAXN 400

ll dp[MAXN+2][MAXN+2];
bool used[MAXN+2][MAXN+2];
vector<ll>a(MAXN+1), suma(MAXN+2);


ll f(int l, int r){
  if(used[l][r])return dp[l][r];
  used[l][r]=true;

  if(l==r)return 0;

  ll sum = suma[r]-suma[l-1];
  ll fans = INF;
  for(int m=l; m<=r; m++){
    fans = min<ll>( fans, f(l, m) + f(m+1, r) );
  }
//cout<<l<<' '<<r<<' '<<sum<<' '<<fans<<endl;
  return dp[l][r] = fans + sum;
}

int main(){
  int n;cin>>n;
  rep(i, n)cin>>a[i];
  ll sum=0;
  rep(i, n)sum+=a[i];
  rep(i, n)suma[i+1]+=suma[i]+a[i];

  cout<<f(1, n)<<endl;

  return 0;

rep(i, n+1){
  rep(j, n+1)cout<<dp[i][j]<<' ';
  cout<<endl;
}

  return 0;
}
