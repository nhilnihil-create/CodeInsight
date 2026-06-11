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
#define INF (int)1e9
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define all(arr) arr.begin(),arr.end()

void boost(){
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int N=102,K=1e5+5;
int arr[N],pre[K];
ll dp[N][K];

void solve(){
  int n,k;
  cin>>n>>k;
  fr(i,1,n+1){
    cin>>arr[i];
  }
  dp[0][0]=1;
  fr(i,0,k+1)
  pre[i]=1;
  fr(i,1,n+1){
    int t=arr[i];
    fr(j,0,k+1){
      dp[i][j]=pre[j];
      if(j-t>0)
        dp[i][j]=(dp[i][j]-pre[j-t-1]+MOD)%MOD;
    }
    pre[0]=dp[i][0];
    fr(j,1,k+1){
      pre[j]=(dp[i][j]+pre[j-1])%MOD;
    }
  }
  cout<<dp[n][k]<<endl;
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