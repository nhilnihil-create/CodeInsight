#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i <= (b); i++)
#define rng(a) a.begin(), a.end()
#define ina(n,a) cin >> n; for(int i = 1; i <= n; i++) cin >> a[i]
#define sz(x) (int)(x).size()
#define se second
#define fi first
#define prev            coyhhhhhhyoc    
#define next          sdNNNmNNNNNNNmds  
#define y0           hNNNNy_yNNNNNN_sNh
#define y1          mNNNNNdtdNNNNNNtsNNm
#define yn          mNNNNNNNNy___smNNNms
#define tm            oooooosyysooooot 
#define read               tyhyt        
#define rank              ytmNmo         
#define index              yyy
#define pb push_back
#define pcnt __builtin_popcountll
#define rrep(i,a,b) for(int i = (b); i >= (a); i--)
#define rall(x,a) for(auto x : a)
#define MOD 1000000007
#define endl "\n"
typedef long long ll;
using namespace std;

const int N = 222;
int dist[11][11], a[N][N];
int n, m;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 1, 10) {
        rep(j, 1, 10) {
            cin >> dist[i][j];
        }
    }
    rep(k, 1, 10) {
        rep(i, 1, 10) {
            rep(j, 1, 10) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int ans = 0;
    rep(i, 1, n) {
        rep(j, 1, m) {
            cin >> a[i][j];
            if(a[i][j] >= 0) {
                ans += dist[a[i][j] + 1][2];
            }
        }
    }
    cout << ans << endl;
    return 0;
}
