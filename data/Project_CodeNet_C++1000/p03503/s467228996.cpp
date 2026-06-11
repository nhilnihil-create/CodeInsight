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
int n;
int f[105][10];
int p[105][15];

int calc(int bit) {
    vi cnt(n, 0);
    rep(d, 10) {
        if (bit>>d&1) {
            rep(i, n) {
                if (f[i][d] == 1) cnt[i]++;
            }
        }
    }
    int res = 0;
    rep(i, n) {
        res += p[i][cnt[i]];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    rep(i, n) {
        rep(j, 10) {
            cin >> f[i][j];
        }
    }

    rep(i, n) for (int j = 0; j <= 10; ++j) cin >> p[i][j];

    int mx = -INF;
    rep(bit, 1<<10) {
        if (bit == 0) continue;
        chmax(mx, calc(bit));
    }
    cout << mx << endl;
}