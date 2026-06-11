//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    int h, w;
    cin >> h >> w;
    vvi dist(10, vi(10, INF));
    rep(i, 10) {
        rep(j, 10) {
            int c;
            cin >> c;
            if(c != -1) {
                dist[i][j] = c;
            }
        }
    }
    vvi a(h, vi(w));
    rep(i, h) {
        rep(j, w) {
            cin >> a[i][j];
        }
    }

    rep(k, 10) {
        rep(i, 10) {
            rep(j, 10) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int ans = 0;
    rep(i, h) {
        rep(j, w) {
            if(a[i][j] != -1) {
                ans += dist[a[i][j]][1];
            }
        }
    }

    cout << ans << endl;
}