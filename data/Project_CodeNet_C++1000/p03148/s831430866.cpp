#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define per(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define sz(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define INF 2e9
#define LINF 1e18
template<class T> inline bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int n, k; cin >> n >> k;
    vector<vector<int> > tmp(n);
    rep(i, n) {
        int t0, d0;
        cin >> t0 >> d0;
        t0--;
        tmp[t0].push_back(d0);
    }

    rep(i, n) sort(all(tmp[i]), greater<int>()); //各ネタごとに美味しさ降順でソート

    vector<int> y1, y0;
    rep(i, n) {
        if (sz(tmp[i]) == 0) continue;
        y1.push_back(tmp[i][0]); //各寿司の一番美味しいやつの味を格納
        for (int j=1; j<sz(tmp[i]); j++) {
            y0.push_back(tmp[i][j]); //一番美味しいやつ以外の味を格納
        }
    }
    sort(all(y1), greater<int>());
    sort(all(y0), greater<int>());
    //以降、各寿司を食う場合は一番美味しいやつを食えばよく
    //その一番美味しいやつを何個食うかで調べていけば良い
    ll ans = 0;
    for (int i=1; i<=min(sz(y1), k); i++) {
        ll tmp = (ll)i*i; //何種類の寿司を食うか
        rep(j, i) tmp += y1[j];
        int m = k-i; //あと何個一番美味しい寿司以外食うか
        if (sz(y0) < m) continue;
        rep(j, m) {
            tmp += y0[j];
        }
        chmax(ans, tmp);
    }

    cout << ans << endl;
}