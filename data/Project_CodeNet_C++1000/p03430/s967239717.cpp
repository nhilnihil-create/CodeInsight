//In the name of Allah
//In the name of the compassionate of the merciful
//Ya Ali!
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename Type>
using ordered_multiset = tree<Type, null_type, less_equal<Type>, rb_tree_tag, tree_order_statistics_node_update> ;

typedef long long ll ;
typedef long double ld ;

#define f first
#define s second
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define all(x) x.begin() , x.end()
#define mp make_pair
#define pll pair<ll,ll>
#define pii pair<int,int>

//ifstream fin("input.txt");
//ofstream fout("output.txt");
// fflush(stdout);

const ll maxn = 310 ;
const ll INF = 1e18 ;

ll mod = 1e9 + 7 , p1 = 999999929 , p2 = 999999937 ;

ll n , k , dp[maxn][maxn][maxn] ;
string s1 ;

int main()
{
std::ios::sync_with_stdio(0) ;
cin.tie(0) ;
cout.tie(0) ;

cin >> s1 >> k ;
n = s1.size() ;

for(int i = 0 ; i < n ; i ++)
  for(int j = 0 ; j <= k ; j ++)
    dp[i][i][j] = 1 ;

for(int r = 1 ; r < n ; r ++){
 for(int l = r-1 ; l >= 0 ; l --){
  for(int co = 0 ; co <= k ; co ++){
    dp[l][r][co] = max(dp[l][r][co] , dp[l+1][r][co]) ;
    dp[l][r][co] = max(dp[l][r][co] , dp[l][r-1][co]) ;
   if(r-l>1){
    if(s1[l] == s1[r])dp[l][r][co] = max(dp[l][r][co] , dp[l+1][r-1][co]+2) ;
    if(co > 0)dp[l][r][co] = max(dp[l][r][co] , dp[l+1][r-1][co-1]+2) ;
   }
   else{
    if(s1[l] == s1[r])dp[l][r][co] = 2 ;
    if(co>0)dp[l][r][co] = 2;
   }
  }
 }
}
cout << dp[0][n-1][k] ;
 return 0;
}
