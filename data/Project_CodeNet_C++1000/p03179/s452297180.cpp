// in the name of Allah
// Ya Ali!
#include <bits/stdc++.h>
using namespace std;

typedef long long ll ;
typedef long double ld ;

const ll maxn = 3011 ;
const ll INF = 1e18 ;

#define f first
#define s second

ll n , mod = 1e9 + 7 , dp[maxn][maxn] , per[maxn][maxn] ;
string s1 ;
char a[maxn][maxn] ;

int main()
{
 std::ios::sync_with_stdio(0) ;
 cin.tie(0) ;
 cout.tie(0) ;

 cin >> n >> s1 ;
 for(int i = 0 ; i < n-1 ; i ++)a[i+1][i+2] = s1[i] ;

 dp[1][1] = 1 ;
 per[1][1] = dp[1][1] ;

 for(int i = 2 ; i <= n ; i ++){
    for(int j = 1 ; j <= i ; j ++){
        if(a[i-1][i] == '>'){
           dp[i][j] = per[i-1][j-1]%mod ;
           //for(int k = j-1 ; k > 0 ; k --)dp[i][j] = (dp[i][j] + (dp[i-1][k]%mod))%mod ;
        }
        else{
           dp[i][j] = (per[i-1][i-1] - per[i-1][j-1] + mod)%mod ;
           //for(int k = j+1 ; k <= i ; k ++)dp[i][j] = (dp[i][j] + (dp[i-1][k-1]%mod))%mod ;
        }
        per[i][j] = (per[i][j-1] + dp[i][j])%mod ;
    }
 }

 ll ans = 0 ;
 for(int i = 1 ; i <= n ; i ++)ans = (ans + (dp[n][i]%mod))%mod ;
 cout << ans%mod ;


    return 0;
}
