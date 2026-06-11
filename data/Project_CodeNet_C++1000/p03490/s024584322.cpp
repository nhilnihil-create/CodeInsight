#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
typedef pair<ll, ll> PP;
#define rep(i, n) for(ll i = 0; i < ll(n); i++)
template <class T> void corner(bool flg, T hoge) {
    if (flg) {
        cout << hoge << endl;
        exit(0);
    }
}
#define all(v) v.begin(), v.end()
#define inputv(v, n)                                                           \
    vl v;                                                                      \
    rep(i, n) {                                                                \
        ll x;                                                                  \
        cin >> x;                                                              \
        v.push_back(x);                                                        \
    }
const ll INF = 999999999999999;
const ll MOD = 1000000007;
const ll MAX_N = 500010;
ll a, b, c, d, e, f, p, t, x, y, z, q, m, n, r, h, k, w, l, ans;
int main() {
    string S;
    cin >> S;
    cin >> x >> y;

    vl X[2];
    a = 0;
    b = 0;
    rep(i, S.length()) {
        if (S[i] == 'F') {
            b++;
        }
        else {
            X[a % 2].push_back(b);
            a++;
            b = 0;
        }
    }
X[a % 2].push_back(b);

    bitset<16001> xx, yy,now;
    x += 8000;
    y += 8000;
    xx.set(8000);
    yy.set(8000);
    rep(i, X[0].size()) {
        if (i == 0)xx=xx<<X[0][0];
        else {
            now = (xx << X[0][i]) | (xx >> X[0][i]);
            xx = now;
        }
    }
    rep(i, X[1].size()) {
        now = (yy << X[1][i]) | (yy >> X[1][i]);
        yy = now;
    }

    cout << (xx[x] && yy[y] ? "Yes" : "No") << endl;
}
