// in the name of Allah
// Ya Ali!
#include <bits/stdc++.h>
using namespace std;

typedef long long ll ;
typedef long double ld ;

const ll maxn = 18 ;
const ll INF = 1e18 ;

#define f first
#define s second

ll n , a[maxn][maxn] , dp[(1<<maxn)] , tmp[(1<<maxn)];

int main()
{
 std::ios::sync_with_stdio(0) ;
 cin.tie(0) ;
 cout.tie(0) ;

 cin >> n ;
 for(int i = 0 ; i < n ; i ++)
   for(int j = 0 ; j < n ; j ++)
     cin >> a[i][j] ;

 for(int mask = 0 ; mask < (1<<n) ; mask ++){
    vector<ll> vv ;
    for(int j = 0 ; j < n ; j ++)if(mask&(1<<j))vv.push_back(j) ;

    for(int i = 1 ; i < vv.size() ; i ++)
     for(int j = 0 ; j < i ; j ++)
         tmp[mask] += a[vv[i]][vv[j]] ;
 }

 dp[0] = 0 ;
 for(int mask = 1 ; mask < (1<<n) ; mask ++)
    for(int mask2 = mask ; mask2 > 0 ; mask2 = (mask2-1)&mask)
      dp[mask] = max(dp[mask] , dp[mask^mask2]+tmp[mask2]) ;

 cout << dp[(1<<n)-1] ;

    return 0;
}
