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
    
    int n, k, q;
    cin >> n >> k >> q;
    vi a(n);
    rep(i, n) cin >> a[i];
    int ans = INF;
    rep(i, n) {
        int mn = a[i];
        int m = 0;
        vi b, c;
        rep(j, n) {
            if (a[j] < mn) {
                sort(b.begin(), b.end());
                rep(x, m - k + 1) {
                    c.pb(b[x]);
                }
                m = 0;
                b = vi(0);
            } else {
                m++;
                b.pb(a[j]);
            }
        }
        sort(b.begin(), b.end());
        rep(x, m - k + 1) {
            c.pb(b[x]);
        }
        if (q-1 >= sz(c)) continue;
        sort(c.begin(), c.end());
        int mx = c[q-1];
        chmin(ans, mx - mn);
    }
    cout << ans << endl;
}