#include <bits/stdc++.h>

#define f(i,a,b) for( ll i = a; i < b ; i++ )
#define af(i,a,b) for( ll i = a; i >= b ; i--)
#define rep(i,a,b,k) for(ll i = a; i < b ; i+= k )
#define arep(i,a,b,k) for( ll i = a; i >= b ; i-= k)
#define ones(x) (ll) __builtin_popcount(x)
#define fs first
#define sc second
#define pb push_back
#define po pop_back
#define mp make_pair  
#define sz(a) (ll) a.size()
#define all(a) a.begin(), a.end()
#define sor(a) sort( a.begin(), a.end() )
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ller ios::sync_with_stdio(false);cin.tsie(nullptr);cout.tie(nullptr)
#define watch(x) cout << (#x) << " is #" << (x) <<"#" <<endl
#define PI 3.1415926535
using namespace std;
typedef long long ll;
typedef long double ld; 
typedef pair<ll,ll> ii ;
typedef vector<ll>  vi ;
typedef vector<ii> vii ;
const ll mod = 1e9+7;
const ll MAX = 3000+4;
const ll inf = 1e18+7;
ll dp[MAX][MAX];
int main(){
  fastio;
  string s,t;
  cin>>s>>t;
  memset(dp,0,sizeof(dp));
  f(i,1,sz(s)+1){
    f(j,1,sz(t)+1){
      if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1]+1;
      else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
    }
  }
  ll i=sz(s),j=sz(t);
  string lcs="";
  while(i>0 && j>0) {
    if(dp[i][j]==dp[i-1][j])  i--;
    else if(dp[i][j]==dp[i][j-1]) j--;
    else {
    lcs+=s[i-1];
    i--,j--;
      }
  }
  reverse(all(lcs));
  cout<<lcs<<"\n";
  return 0; 
}