#include <bits/stdc++.h>

//#define DEBUG 1

//#define int long long
#define for0(i,n) for (int i=0; i<n; i++)
#define iter(c) for(auto it=c.begin(); it!=c.end(); it++)
#define iter2(c) for(auto it2=c.begin(); it2!=c.end(); it2++)
#define pb push_back
#define ms(a,z) memset(a,z,sizeof(a));
#define mp make_pair
#define X first
#define Y second
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define all(a) a.begin(),a.end()
#define sz(x) (int)(x).size()
#define pmod(x,m) (((x)%(m)+m)%m)
#ifdef int
#define read(x) scanf("%lld",&x);
#else
#define read(x) scanf("%d",&x);
#endif

#ifdef DEBUG
#define nl cout<<"\n";
#define pr(x) cout<<(x)<<" ";
#define prl(x) cout<<#x " = "<<x<<endl;
#define prp(x) cout<<"("<<(x).first<<" "<<(x).second<<") ";
#define printv(v) {for(int _=0; _<sz(v); _++) cout<<v[_]<<" "; cout<<"\n";}
#define printa(a,s) {for (int _=0; _<s; _++) cout<<a[_]<<" "; cout<<"\n";}
#define print2D(a,m,n) {for (int _=0; _<m; _++) {for (int __=0; __<n; __++) cout<<a[_][__]<<" "; cout<<"\n";} cout<<"\n";}
#define priter(v) iter(v) {pr(*it)} nl
#define debug cout<<"ok at line "<<__LINE__<<endl;
#else
#define nl
#define pr(x)
#define prl(x)
#define prp(x)
#define printv(v)
#define printa(a,s)
#define print2D(a,m,n)
#define priter(v)
#define debug
#endif
#define MAXN 100000

using namespace std;

typedef long long ll;

const int INF = 2147483647;
const long long INFL = 9223372036854775807LL;
const double EPSILON = 0.00000001;
const long long MOD = 1000000007;

int dp[305][305][305];

int32_t main()
{
    #ifdef DEBUG
    //freopen("C.txt","r",stdin);
    //freopen("","w",stdout);
    #endif

    string s;
    int K;
    cin >> s;
    cin >> K;
    int n = s.length();
    s = "3"+s;
    
    ms(dp,0);
    for (int i=1; i<=n; i++) {
        for (int k=0; k<=K; k++) {
            dp[k][i][i] = 1;
        }
    }
    
    for (int k=0; k<=K; k++) {
        for (int i=n; i>=1; i--) {
            for (int j=i; j<=n; j++) {
                //pr(i) pr(j) nl
                int v = 0;
                v = max(v, dp[k][i+1][j]);
                v = max(v, dp[k][i][j-1]);
                if (s[i] == s[j])
                    v = max(v, dp[k][i+1][j-1]+2-(i==j));
                else if (k > 0)
                    v = max(v, dp[k-1][i+1][j-1]+2-(i==j));
                dp[k][i][j] = v;
            }
        }
    }
    print2D(dp[0],n+1,n+1);
    int ans = dp[K][1][n];
    cout<<ans<<endl;
    return 0;
}
