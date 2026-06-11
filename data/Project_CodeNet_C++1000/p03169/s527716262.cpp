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

const int N=307;
double dp[N+5][N+5][N+5];
void solve(){
  int n ;cin>>n;
  vi cnt(4);
  for(int i=0;i<n;i++){
    int x;cin>>x;
    cnt[x]++;
  }
  for(int c=0;c<N;c++){
    for(int b=0;b<N;b++){
      for(int a=0;a<N;a++){
        if(a+b+c==0)continue;
        if(a+b+c>N)continue;
        double p=1.0*n/(a+b+c);
        double p1=1.0*a/(a+b+c);
        double p2=1.0*b/(a+b+c);
        double p3=1.0*c/(a+b+c);
        if(a)dp[a][b][c]+=p1*dp[a-1][b][c];
        if(b)dp[a][b][c]+=p2*dp[a+1][b-1][c];
        if(c)dp[a][b][c]+=p3*dp[a][b+1][c-1];
        dp[a][b][c]+=p;
        //cout<<p1<<" "<<p2<<" "<<p3<<endl;
      }
    }
  }
  
  cout<<fixed<<setprecision(10)<<dp[cnt[1]][cnt[2]][cnt[3]];

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