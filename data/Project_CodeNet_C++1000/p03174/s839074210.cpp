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

const int N=21,M=(1<<N);
ll dp[N][M];
int n,arr[N][N];

ll fun(int i,int mask){
  if(i!=__builtin_popcount(mask))
    return dp[i][mask]=0;
  if(dp[i][mask]!=-1)
    return dp[i][mask];
  ll ans=0;
  fr(j,0,n){
    if(arr[i][j]==1 && ((mask>>j)&1)==0){
      ans+=fun(i+1,mask^(1<<j));
      ans%=MOD;
    }
  }
  return dp[i][mask]=ans;
}

void solve(){
  cin>>n;
  fr(i,0,n){
    fr(j,0,n){
      cin>>arr[i][j];
    }
  }
  fr(i,0,N){
    fr(j,0,M){
      dp[i][j]=-1;
    }
  }
  fr(j,0,(1<<n))
  dp[n-1][j]=0;
  fr(j,0,n){
    if(arr[n-1][j]==1){
      dp[n-1][((1<<n)-1)^(1<<j)]=1;
    }
  }
  ll ans=0;
  cout<<fun(0,0);
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