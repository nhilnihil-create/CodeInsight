#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
void debug() { cerr << "\n"; }
template <class T> void debug(const T &x) { cerr << x << "\n"; }
template <class T, class... Args> void debug(const T &x, const Args &... args) {
    cerr << x << " ";
    debug(args...);
}
template <class T> void debugVector(const vector<T> &v) {
    for(const T &x : v) {
        cerr << x << " ";
    }
    cerr << "\n";
}
using ll = long long;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
constexpr int MOD = 1000000007;
const int dx[] = {1, 0, -1, 0, -1, -1, 1, 1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

//-------------------------------------

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h, w;
    cin >> h >> w;
    vector<string> g(h);
    for(int i = 0; i < h; i++) {
        cin >> g[i];
    }
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(g[i][j] == '.') {
                int cnt = 0;
                for(int r = 0; r < 8; r++) {
                    int ni = i + dy[r];
                    int nj = j + dx[r];
                    if(0 <= ni && ni < h && 0 <= nj && nj < w &&
                       g[ni][nj] == '#') {
                        cnt++;
                    }
                }
                g[i][j] = (char)('0' + cnt);
            }
        }
    }
    for(int i = 0; i < h; i++) {
        cout << g[i] << "\n";
    }
}