#include <bits/stdc++.h>
using namespace std;

struct Fast {Fast(){cin.tie(0);ios::sync_with_stdio(0);}} fast;
using intpair = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define ceiv(a, b) ((int)((a) + (b) - 1)/(int)(b))
//#define int long long

signed main(){
    int n; cin >> n;
    vector<bitset<10>> f(n);
    vector<vector<int>> p(n,vector<int>(11));
    rep(i,n){
        string s = "";
        rep(j,10){
            char c; cin >> c;
            s.push_back(c);
        }
        f[i] = bitset<10>(s);
    }
    rep(i,n)rep(j,11) cin >> p[i][j];
    
    bitset<10> b;
    int ans = INT_MIN;
    reps(i, 1, (1 << 10) -1){
        b = i;
        int x = 0;
        rep(j,n){
            bitset<10> t = b & f[j];
            x += p[j][t.count()];
        }
        ans = max(ans, x);
    }
    cout << ans << endl;
}