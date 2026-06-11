#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR(i,k,n) for(ll i=(k);(k)<(n)?i<(n):i>(n);(k)<(n)?i+=1:i-=1)
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int INF = 1<<29;
typedef long long ll;
typedef unsigned long long ull;
typedef vector< ll > vi;
typedef vector< vi > vvi;
typedef pair< ll,ll > ii;
#define F first
#define S second
#define EB emplace_back
#define PB push_back
#define MP make_pair
#define sz(a) ll((a).size())
#define all(o) (o).begin(), (o).end()
#define present(container, element) (container.find(element) != container.end())
#define cpresent(container, element) (find(all(container),element) != container.end())
#define TR(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }

const int MOD = 1000000007;
ll fastpowMOD(ll a, ll p,ll MOD){ if(p==0) return 1; ll z = fastpowMOD(a,p/2,MOD); z = (z*z)%MOD; if(p%2) z = (z*a)%MOD; return z; }
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

struct block{
  ll w,s,v;
  block(ll w=0,ll s=0,ll v=0): w(w),s(s),v(v){}
  bool operator<(const block& b){
    return (w+s<b.w+b.s);
  }
};
ll dp[2][2*10010];
void solve(){
  int N;
  cin>>N;
  vector<block> blocks;
  blocks.reserve(N);
  int MAX_S=0;
  FOR(i,0,N){
    int w,s,v;
    cin>>w>>s>>v;
    MAX_S=max(MAX_S,s);
    blocks.EB(w,s,v);
  }
  MAX_S*=2;
  sort(blocks.begin(),blocks.end());
  FOR(i,0,N){
    // debug(blocks[i].w,blocks[i].s,blocks[i].v);
  }
  int k=1;
  memset(dp,-1,sizeof(dp));
  dp[0][0]=0;
  FOR(i,0,N){
    ll cw=blocks[i].w,cs=blocks[i].s,cv=blocks[i].v;
    FOR(j,0,MAX_S+1){
      if(j<cw||j-cw>cs){
        dp[k][j]=dp[k^1][j];
      }else{
        if(dp[k^1][j-cw]!=-1){
          dp[k][j]=dp[k^1][j-cw]+cv;
        }
        dp[k][j]=max(dp[k][j],dp[k^1][j]);
      }
      // debug(i,j,dp[k][j]);
    }
    k^=1;
  }
  ll max_val=0;
  FOR(j,0,MAX_S+1){
    // debug(j,max_val,dp[k^1][j]);
    max_val=max(max_val,dp[k^1][j]);
  }
  cout<<max_val<<'\n';

}
int main()
{
  fastio
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  #endif
  solve();
  return 0;
}
