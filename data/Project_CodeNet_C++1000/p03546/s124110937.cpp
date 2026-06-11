#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ll long long
#define P pair<int,int>
const int MOD = 1000000007;
const int INF = 2002002002;
const ll LLINF = 9009009009009009009;
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    int c[10][10];
    rep(i,10) {
        rep(j,10) cin >> c[i][j];
    }

    rep(k,10) {
        rep(i,10) {
            rep(j,10) {
                c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
            }
        }
    }

    int ans = 0;
    int a;
    rep(i,h) {
        rep(j,w) {
            cin >> a;
            if (a == -1) continue;
            ans += c[a][1];
        }
    }
    cout << ans << endl;
    return 0;
}