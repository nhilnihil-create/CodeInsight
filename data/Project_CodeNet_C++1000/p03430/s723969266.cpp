#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define IN freopen("perimetric_chapter_1_input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)

#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for(i=a ; i<=b ; i++)
#define DBG printf("Hi\n")
#define i64 long long int
#define ui64 unsigned long long int
#define xx first
#define yy second
#define ln 17
#define off 2002

#define sq(x) ((x)*(x))

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL)

using namespace __gnu_pbds;
using namespace std ;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef tree< i64, null_type, less<i64>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef pair<int,int> pii;

#define log 20
#define mod 1000000007LL
#define INF 1000000000000000000LL
#define maxn 300005

const long double eps = 1e-9 ;

char s[305] ;

int dp[305][305][305] ;

int f(int l, int r, int k)
{
    if( l>r ) return 0 ;
    if(l==r) return dp[l][r][k] = 1 ;
    if( dp[l][r][k] != -1 ) return dp[l][r][k] ;

    if(s[l]==s[r]) return dp[l][r][k] = f(l+1,r-1,k) + 2 ;
    int ret = max(f(l+1,r,k) , f(l,r-1,k)) ;
    if(k>0) ret = max( ret , f(l+1,r-1,k-1) + 2 ) ;
    return dp[l][r][k] = ret ;
}

int main()
{
    scanf("%s",s) ;
    int k ;

    scanf("%d",&k) ;

    memset(dp,-1,sizeof(dp)) ;

    int n = strlen(s) ;
    printf("%d\n", f(0,n-1,k)) ;

    return 0 ;
}
