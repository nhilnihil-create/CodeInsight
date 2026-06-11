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
#define int long long
typedef long long ll;
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    rep(a, 1, 3500) {
        rep(b, 1, 3500) {
            int m = 4 * a * b - n * a - n * b;
            if(m <= 0) continue;
            int lo = 1, hi = 3500;
            while(lo < hi) {
                int mi = lo + (hi - lo) / 2;
                int x = mi * m;
                if(x < n * a * b) {
                    lo = mi + 1;
                } else {
                    hi = mi;
                }
            }
            int x = lo * m;
            if(x == n * a * b) {
                cout << a << " " << b << " " << lo << endl;
                return 0;
            }
        }
    }
    return 0;
}
