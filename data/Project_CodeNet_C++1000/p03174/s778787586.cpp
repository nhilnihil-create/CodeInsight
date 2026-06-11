#include<bits/stdc++.h>
using namespace std;

//#define int long long int
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define lb lower_bound
#define ub upper_bound
#define srt(a) sort(a.begin(),a.end())
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pair<int,int>> vpii;
#define mxe(a) *max_element(a.begin(),a.end())
#define mne(a) *min_element(a.begin(),a.end())
#define setbit(x) __builtin_popcount(x)
#define setbitl(x) __builtin_popcountll(x)
#define endl '\n'
#define mod 1000000007
#define INF64 1e18

void solve(){
  int n ;cin>>n;
  bool c[n][n];
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin>>c[i][j];
  int tot=1<<n;
  vi dp(tot);
  dp[0]=1;
  for(int mask=0;mask<tot;mask++){
    for(int w=0;w<n;w++){
      if((mask&(1<<w))==0){
        dp[mask|(1<<w)]+=c[__builtin_popcount(mask)][w]*dp[mask];
        dp[mask|(1<<w)]%=mod;
      }
    }
  }
  cout<<dp[tot-1];
}

int32_t main(){
  #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
  #endif
  
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int T=1;
  //cin>>T;
  for(int TT=1;TT<=T;TT++){
    solve();
  }
}