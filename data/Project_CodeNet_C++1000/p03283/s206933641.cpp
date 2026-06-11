#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(v) v.begin(), v.end()
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
    
    int n, m, q;
    cin >> n >> m >> q;
    vvi trains(n, vi(n, 0));
    rep(i, m) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        trains[l][r]++;
    }
    vvi sm(n+1, vi(n+1, 0));
    rep(i, n) rep(j, n) {
        sm[i+1][j+1] = sm[i+1][j] + sm[i][j+1] - sm[i][j] + trains[i][j];
    }
    rep(i, q) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        int ans = sm[n][b+1] - sm[n][0] - sm[a][b+1] + sm[a][0];
        cout << ans << endl;
    }

}