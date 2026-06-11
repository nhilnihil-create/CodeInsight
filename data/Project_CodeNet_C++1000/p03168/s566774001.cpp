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
const ll MAX = 3e3+7;
const ll inf = 1e18+7;
ld prob[MAX],ans=0;
ld dp[MAX][MAX];
int main() {
  fastio;
  ll n;
  cin>>n;
  f(i,1,n+1) cin>>prob[i];
  
  dp[1][0] = 1.0 - prob[1];

  f(i,2,n+1) dp[i][0] = dp[i-1][0]*(1.0-prob[i]);

  dp[1][1] = prob[1];

  f(i,2,n+1) dp[i][i] = dp[i-1][i-1]*prob[i];

  f(i,1,n+1){
    f(j,1,i) {
      dp[i][j] = dp[i-1][j]*(1.0 - prob[i]) + dp[i-1][j-1]*prob[i];
    }
  }

  f(i,n/2 + 1,n+1) ans += dp[n][i];
  cout<<fixed<<setprecision(10)<<ans;
  return 0; 
}