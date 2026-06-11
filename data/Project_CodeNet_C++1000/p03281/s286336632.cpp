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

int solve(int x) {
    int di = 0;
    for(int d = 1; d <= x; d++) {
        if(x % d == 0) {
            di++;
        }
    }
    return di == 8;
}

int solve() {
    int n;
    cin >> n;
    int ans = 0;
    rep(x, 1, n) {
        if(x & 1) {
            ans += solve(x);
        }
    }
    cout << ans << endl;
    return 0;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}
