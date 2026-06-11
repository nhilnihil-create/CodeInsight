#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vll = vector<long long>;
using vp = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

const int INF = 1001001001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vvll grid(101, vll(101, -1));
    ll a, b;
    rep(i, n) {
        ll x, y, h;
        cin >> x >> y >> h;
        if (h > 0) {
            a = x;
            b = y;
        }
        grid[x][y] = h;
    }
    
    rep(cx, 101) {
        rep(cy, 101) {
            bool flag = true;
            ll h = grid[a][b] + abs(a - cx) + abs(b - cy);
            rep(i, 101) {
                rep(j, 101) {
                    if (grid[i][j] == -1) continue;
                    if (grid[i][j] !=  max(h - abs(i - cx) - abs(j - cy), 0LL)) {
                        flag = false;
                    }
                }
            }
            if (flag) {
                cout << cx << " " << cy << " " << h << endl;
                return 0;
            }
        }
    }
}