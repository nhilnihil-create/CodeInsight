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
const int N=3005;
int dp[N][N];
void solve(){
  int n ;
  string s;
  cin>>n>>s;
  int l,r;
  vi pref(n+1,1);
  pref[0]=0;
  for(int i=2;i<=n;i++){
    vi p(n+1);
    for(int j=1;j<=i;j++){
      if(s[i-2]=='<')l=1,r=j-1;
      else l=j,r=i-1;
      dp[i][j]=(mod+pref[r]-pref[l-1])%mod;
      p[j]=(p[j-1]+dp[i][j])%mod;
    }
    pref=p;
  }
  cout<<pref[n];
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