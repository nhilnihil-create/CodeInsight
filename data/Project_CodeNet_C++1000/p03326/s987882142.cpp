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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vvll a(n, vll(3));
    rep(i, n) cin >> a[i][0] >> a[i][1] >> a[i][2];
    ll ans = 0;
    for (int bit = 0; bit < 1<<3; ++bit) {
        vll b(n, 0);
        rep(j, 3) {
            if (bit>>j&1) {
                rep(i, n) b[i] += a[i][j];
            } else {
                rep(i, n) b[i] -= a[i][j];
            }
        }
        sort(b.rbegin(), b.rend());
        chmax(ans, accumulate(b.begin(), b.begin()+m, 0LL));
    }
    cout << ans << endl;
}