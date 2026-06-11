#include<bits/stdc++.h>
using namespace std;

#define int long long int
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
#define endl '\n'
#define mod 1000000007
#define INF64 1e18
const int N=105;
const int K=100005;
int dp[N][K];
void solve(){
  int n,k;cin>>n>>k;
  vi a(n+1);
  for(int i=1;i<=n;i++)
    cin>>a[i];
  for(int i=0;i<=n;i++)dp[i][0]=1;
  vi pref(k+1,1);
  for(int i=1;i<=n;i++){
    vi p(k+1);
    p[0]=1;
    for(int j=1;j<=k;j++){
      dp[i][j]=(mod+pref[j]-(j-a[i]-1>=0?pref[j-a[i]-1]:0))%mod;
      p[j]=(p[j-1]+dp[i][j])%mod;
    }
    pref=p;
  }
  cout<<dp[n][k];
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
