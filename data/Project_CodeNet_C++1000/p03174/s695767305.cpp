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
  const ll MAX = 21;
  const ll inf = 1e18+7;

  ll n;
  ll a[MAX][MAX];
  ll dp[MAX][1<<MAX];
  ll DP(ll u,ll m){
    if(u == n) return 1;
    ll &ans = dp[u][m];
    if(ans!=-1) return ans;
    ans = 0;
    f(i,0,n){
      if(a[u][i] && (m>>i)&1) {ans = (ans+DP(u+1,m&(~(1 << i))))%mod;}
    }
    return ans;
  }

  int main(){
    fastio;
    cin>>n;
    f(i,0,n){ 
      f(j,0,n) cin>>a[i][j];
    }
    f(i,0,MAX){
      f(j,0,(1<<MAX)) dp[i][j]=-1;
    }
    cout<<DP(0,(1<<n)-1)<<"\n";
    return 0; 
  }