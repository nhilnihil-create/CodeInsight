#include<bits/stdc++.h>
using namespace std;
 
typedef    long long          ll;
typedef    vector<long long>    vi; 
typedef    vector<vi>         vvi; 
typedef    pair<long,long>      ii; 
#define    sz(a)              long((a).size()) 
#define    pb                 push_back 
#define    mp                   make_pair
#define    all(c)             (c).begin(),(c).end() 
#define    tr(c,i)            for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define    present(c,x)       ((c).find(x) != (c).end()) 
#define    cpresent(c,x)      (find(all(c),x) != (c).end())  
#define    input(v,n)           for(ll i = 0 ; i<n ; i++) cin>>v[i]
#define    output(v,n)          for(ll i = 0 ; i<n ; i++) cout<<v[i]<<" "


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
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}\n";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
 
ll mod = 1e9 + 7;


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,i,j;
  cin>>n;
  string s;
  cin>>s;

  vector< vi  > dp(n+3,vi(n+3,0));

  dp[0][1]=1;

  for(i=0;i<n-1;i++)
  {

    for(j=1;j<=i+2;j++)
    {
      if(s[i]=='>')
      {
        dp[i+1][j]=(dp[i][i+1]-dp[i][j-1])%mod;
      }
      else 
      {
        dp[i+1][j]=(dp[i][j-1]-dp[i][0])%mod;
      }
    }

    for(j=1;j<=i+2;j++)
      {dp[i+1][j]+=dp[i+1][j-1];dp[i+1][j]%=mod;}
  }

  //debug(dp);

  cout<<(dp[n-1][n]+mod)%mod;




  return 0;
}
