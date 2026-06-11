#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
#define fr(i,k,n) for (int i = k; i < n; ++i)
#define fri(i,k,n) for (int i = k; i >= n; --i)
#define INF (ll)1e16
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define all(arr) arr.begin(),arr.end()

void boost(){
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

ll dp[402][402],sum[402][402];

ll fun(int i,int j){
  if(dp[i][j])
    return dp[i][j];
  ll mn=INF;
  fr(k,i,j)
    mn=min(mn,fun(i,k)+fun(k+1,j));
  return dp[i][j]=sum[i][j]+mn;
}

void solve(){
  int n;
  cin>>n;
  fr(i,0,n){
    cin>>dp[i][i];
    sum[i][i]=dp[i][i];
  }
  fr(i,0,n-1){
    fr(j,i+1,n){
      sum[i][j]=sum[i][j-1]+dp[j][j];
    }
  }
  cout<<fun(0,n-1)-sum[0][n-1]<<endl;
  return;
}

int main()
{
  boost();
  
  int tc=1;
  //cin>>tc;
  while(tc--)
    solve();
  return 0;
}