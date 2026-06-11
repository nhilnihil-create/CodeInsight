#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vs = vector<string>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

const int INF = 1001001001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, c;
    cin >> n >> c;
    vvi d(c, vi(c));
    rep(i, c) rep(j, c) cin >> d[i][j];
    vvi color(n, vi(n));
    rep(i, n) rep(j, n) {
        cin >> color[i][j];
        color[i][j]--;
    }
    
    vvi now(3, vi(c, 0));
    rep(i, n) rep(j, n) {
        int k = ((i+1) + (j+1)) % 3;
        now[k][color[i][j]]++;
    }

    int ans = INF;

    for (int c0 = 0; c0 < c; ++c0) {
        for (int c1 = 0; c1 < c; ++c1) {
            if (c0 == c1) continue;
            for (int c2 = 0; c2 < c; ++c2) {
                if (c0 == c2 || c1 == c2) continue;
                int cost = 0;
                rep(i, c) cost += d[i][c0] * now[0][i];
                rep(i, c) cost += d[i][c1] * now[1][i];
                rep(i, c) cost += d[i][c2] * now[2][i];
                chmin(ans, cost);
            }
        }
    }

    cout << ans << endl; 
}