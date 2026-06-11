#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3+7, MOD = 1e9+7;
ll g[N][N], h, w, memo[N][N];
ll go(int i, int j) {
    if (i==h-1 && j==w-1) return 1;
    if (memo[i][j] != -1) return memo[i][j];
    ll tot = 0;
    if (i+1 < h && !g[i+1][j]) { tot += go(i+1, j); tot%=MOD; }
    if (j + 1 < w && !g[i][j+1]) { tot += go(i, j+1);tot%=MOD; }
    return memo[i][j] = tot;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        string s; cin >> s;
        for (int j = 0; j < w; j++) {
            char x=s[j];
            if (x == '#') g[i][j]=x;
            else g[i][j]= 0;
        }
    }
    memset(memo, -1, sizeof memo);
    int ans = go(0,0)%MOD;
    cout << ans << endl;

    return 0;
}