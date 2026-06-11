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

const int N = 111111;
int v[N], ne[N], no[N];
int n;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int m = 0;
    rep(i, 1, n) {
        cin >> v[i];
        m = max(m, v[i]);
        if(i & 1) {
            no[v[i]]++;
        } else {
            ne[v[i]]++;
        }
    }
    if(n == 2) {
        cout << 0 << endl;
        return 0;
    }
    int me = 0, mee = 0;
    int mo = 0, moo = 0;
    rep(x, 1, m) {
        if(ne[x] >= ne[me]) {
            mee = me, me = x;
        } else if(ne[x] >= ne[mee]) {
            mee = x;
        }
        if(no[x] >= no[mo]) {
            moo = mo, mo = x;
        } else if(ne[x] >= no[moo]) {
            moo = x;
        }
    }
    int ans = n - (me != mo ? ne[me] + no[mo] : max(ne[me] + no[moo], ne[mee] + no[mo]));
    cout << ans << endl;
    return 0;
}
