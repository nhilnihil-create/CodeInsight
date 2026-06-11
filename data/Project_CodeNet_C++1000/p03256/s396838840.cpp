#include <bits/stdc++.h>
 
 
#define pb push_back
#define nl puts ("")
#define sp printf ( " " )
#define phl printf ( "hello\n" )
#define ff first
#define ss second
#define POPCOUNT __builtin_popcountll
#define RIGHTMOST __builtin_ctzll
#define LEFTMOST(x) (63-__builtin_clzll((x)))
#define MP make_pair
#define FOR(i,x,y) for(vlong i = (x) ; i <= (y) ; ++i)
#define ROF(i,x,y) for(vlong i = (y) ; i >= (x) ; --i)
#define CLR(x,y) memset(x,y,sizeof(x))
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define NUMDIGIT(x,y) (((vlong)(log10((x))/log10((y))))+1)
#define SQ(x) ((x)*(x))
#define ABS(x) ((x)<0?-(x):(x))
#define FABS(x) ((x)+eps<0?-(x):(x))
#define ALL(x) (x).begin(),(x).end()
#define LCM(x,y) (((x)/gcd((x),(y)))*(y))
#define SZ(x) ((vlong)(x).size())
#define NORM(x) if(x>=mod) x-=mod;if(x<0) x+=mod;
#define MOD(x,y) (((x)*(y))%mod)
#define ODD(x) (((x)&1)==0?(0):(1))
#define Set(N,cur) N=(N|(1LL<<cur))
#define Reset(N,cur) N=(N&(~(1LL<<cur)))
#define Check(N,cur) (!((N&(1LL<<cur))==0))
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)
#define dump(x) cerr<<"~ "<<#x<<" = "<<x<<endl
//Imran addition
#define rep(i,n) for(int i = 1; i <= n; i++)
#define mem CLR
#define pf printf
#define sc scanf
#define endl "\n"
#define gi(k) scanf("%d",&k)
#define gl(k) scanf("%lld",&k)
#define NMAX 2147483647
#define LMAX 9223372036854775807LL
 
using namespace std;
 
 
#define LL long long
#define LLU long long unsigned int
typedef long long vlong;
typedef unsigned long long uvlong;
typedef pair < int, int > pii;
typedef pair < vlong, vlong > pll;
typedef vector<int> vi;
typedef vector<vlong> vl;
typedef vector<pll> vll;
 
inline vlong gcd ( vlong a, vlong b ) {
    a = ABS ( a ); b = ABS ( b );
    while ( b ) { a = a % b; swap ( a, b ); } return a;
}
 
 
const vlong inf = 2147383647;
const vlong mod = 1000000007;
const double pi = 2 * acos ( 0.0 );
const double eps = 1e-9;
 
 
#define N 200005

int ar[N][2],br[N],taken[N] ;
char s[N];
vector<int> adj[N],v;

int main() {

    //#ifdef forthright48
    //freopen ( "00_input.txt", "r", stdin ); //freopen ( "00_output.txt", "w", stdout );
 	//#endif

    int n,m,x,y;

    cin >> n >> m;

    scanf(" %s",s+1);
    //printf("DD %s\n",s);

    for(int i = 1; i <= m; i++) {
        scanf("%d %d",&x,&y);

        ar[x][ s[y]-'A' ]++;
        ar[y][ s[x]-'A' ]++;

        //adj[x][ keep[x]++ ] = y; adj[y][ keep[y]++ ] = x;

        adj[x].pb(y);
        adj[y].pb(x);
    }

    int cnt = 0;

    for(int i = 1; i <= n; i++) {
        if(!ar[i][0] || !ar[i][1]) {
            //br[++cnt] = i;
            v.pb(i);
            taken[i] = 1;
        }
    }

    for(int i = 0; i < SZ(v); i++) {
        x = v[i];

        for(int j = 0; j < SZ(adj[x]); j++) {
            y = adj[x][j];

            ar[y][ s[x]-'A' ]--;
            
            if(!ar[y][ s[x]-'A' ] && !taken[y]) {
                v.pb(y);
                taken[y] = 1;
            }
        }
    }

    cnt = SZ(v); //dump(cnt);

    if(cnt < n) printf("Yes\n");
    else printf("No\n");

    return 0;
}
