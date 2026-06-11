#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) REP(i, 0, n)
#define rrep(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define sz(x) int(x.size())
#define bitsz(x) int(__builtin_popcount(x))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb(x) push_back(x)
#define INF 2e9
#define LINF 1e18
#define mod 1000000007
template<class T> inline bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (a > b) { a = b; return 1; } return 0; }
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
const int di[4] = {1,0,-1,0};
const int dj[4] = {0,1,0,-1};


int d[10][10]; //d[u][v]は辺e=(u,v)のコスト,存在しないならINF(d[i][i]=0)
int n = 10; //頂点数

void warshall_floyd() {
    rep(k,n) {
        rep(i,n) {
            rep(j,n) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main() {
    int h,w; cin >> h >> w;
    rep(i,10)rep(j,10) cin >> d[i][j];
    int a[h][w];
    rep(i,h)rep(j,w) cin >> a[i][j];
    warshall_floyd();
    int ans = 0;
    rep(i,h)rep(j,w) {
        if (a[i][j]==-1) continue;
        ans += d[a[i][j]][1];
    }
    cout << ans << endl;
}