#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(int i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(int i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define uniq(x) (x).erase(unique((x).begin(), (x).end()), (x).end())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    const int inf = 1e9 + 7;
    vector<vector<int>> d(4, vector<int>(4, inf));
    rep(i, 4) d[i][i] = 0;
    int md = 0;
    
    rep(i, 3) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        d[a][b] = 1;
        d[b][a] = 1;
    }
    
    rep(i, 4) {
        rep(ii, 4) {
            rep(iii, 4) {
                d[ii][iii] = min(d[ii][iii], d[ii][i] + d[i][iii]);
            }
        }
    }
    
    rep(i, 4) {
        rep(ii, 4) {
            md = max(md, d[i][ii]);
        }
    }
    
    cout << ((md == 3) ? "YES" : "NO") << endl;
    return 0;
}
