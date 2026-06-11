#include "bits/stdc++.h"
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long int
#define int ll
//#define slld(t) scanf("%lld",&t)
//#define sd(t) scanf("%d",&t)
//#define pd(t) printf("%d\n",t)
//#define plld(t) printf("%lld\n",t)
#define vec vector < int >
#define vecp vector < pair < int , int > >
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug(x)   cerr<<#x<<": "<<x<<endl
#define pii pair < int , int >
#define pll pair < ll , ll > 
#define debug(x)   cerr<<#x<<": "<<x<<endl
// #define mod  1000000007
#define N 102
// #define MAX 200005
#define mod1 1000000007
#define mod2 998244353
#define bitcnt __builtin_popcount
#define PI acos(-1)
//#define endl "\n"
const int inf = (int)1e18 + 10;
vector < pair< pii , int > >  v;
int dp[1003][20004] = {{0}};
const int MAX = 20000;
bool cmp(pair < pii , int >  a , pair< pii , int > b){
    if(a.ff.ff + a.ff.ss  == b.ff.ff + b.ff.ss)
      return (a.ff.ss < b.ff.ss);
    else
    return (a.ff.ff + a.ff.ss < b.ff.ff + b.ff.ss);
  }
signed main(){
  fast;
  int n , ans = 0;
   cin >> n;
   v.resize(n);
   for(int i = 0 ; i < n ; i++){
        cin >> v[i].ff.ff >> v[i].ff.ss >> v[i].ss;
   }

   sort(v.begin() , v.end() , cmp);
   dp[0][v[0].ff.ff] = v[0].ss;
   for(int i = 1  ; i < n ; i++){
        for(int j = 0 ; j<=   MAX ; j++){
           dp[i][j] = max(dp[i][j] , dp[i-1][j]);
           if(j  <= v[i].ff.ss && j + v[i].ff.ff <= MAX){
            if(dp[i-1][j] > 0 || j == 0 )
               dp[i][j + v[i].ff.ff] = max(dp[i][j + v[i].ff.ff] , dp[i-1][j] + v[i].ss);
            
           }

           // cout << i << " " << j << " " << dp[i][j]<<endl;
          
        }
   }


   for(int i = 0 ; i<=MAX ; i++)
    ans = max(ans , dp[n-1][i]);

  cout << ans << endl;


}	