#include <bits/stdc++.h>     

//#pragma GCC optimize("Ofast")
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4"

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define ll long long
#define int ll
#define forn(i, a, b) for(int i = (a); i <= (b); ++i)
#define forev(i, b, a) for(int i = (b); i >= (a); --i)
#define VAR(v, i) __typeof( i) v=(i)
#define forit(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define file(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
 
using namespace std;
 
const int maxn = (int)4e3;
const int mod = (int)1e9 + 7;
 
#define inf mod
 
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;   
typedef vector<ll> Vll;               
typedef vector<pair<int, int> > vpii;
typedef vector<pair<ll, ll> > vpll;

int n,dp[maxn][maxn],s[maxn][maxn];
char c[maxn];
main () {
  cin>>n;
  forn(i,1,n-1)
    cin>>c[i];
  forn(i,1,n){
    forn(j,1,i){
      if(i==1){
        dp[i][j]=1;
      }else{
        if(c[i-1]=='>')
          dp[i][j]=(s[i-1][i-1]-s[i-1][j-1]+mod)%mod;
        else
          dp[i][j]=s[i-1][j-1];
      }
      s[i][j]=(s[i][j-1]+dp[i][j])%mod;
    }
  }
  int ans=0;
  forn(i,1,n)
    ans=(ans+dp[n][i])%mod;
  cout<<ans;
}