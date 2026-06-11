#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
typedef pair<ll, ll> PP;
#define rep(i, n) for(ll i = 0; i < ll(n); i++)
#define all(v) v.begin(), v.end()
#define inputv(v, n)                                                           \
    vl v;                                                                      \
    rep(i, n) {                                                                \
        ll x;                                                                  \
        cin >> x;                                                              \
        v.push_back(x);                                                        \
    }
bool chmin(ll& a, ll& b) { if (b < a) { a = b; return 1; } return 0; }
bool chmax(ll& a, ll& b) { if (b > a) { a = b; return 1; } return 0; }
const ll INF = 999999999999999;
const ll MOD = 1000000007;
const ll MAX_N = 500010;
ll a, b, c, d, e, f, p, t, x, y, z, q, m, n, r, h, k, w, l, ans;
int main() {
    cin >> n >> c;
    vl A, B,C,D;
    rep(i, n) {
        cin >> a >> b;
        A.push_back(a);
        B.push_back(b);
        C.push_back(c - a);
        D.push_back(b);
    }
    reverse(all(C));
    reverse(all(D));


    a = 0;
    vl X, Y, Z, W;
    rep(i, n) {
        a += B[i];
        X.push_back(a - A[i]);
        Y.push_back(a - A[i] * 2);
    }

    a = 0;

    rep(i, n) {
        a += D[i];
        Z.push_back(a - C[i]);
        W.push_back(a - C[i] * 2);
    }

    rep(i, n-1) {
        X[i + 1] = max(X[i + 1], X[i]);
        Y[i + 1] = max(Y[i + 1], Y[i]);
        Z[i + 1] = max(Z[i + 1], Z[i]);
        W[i + 1] = max(W[i + 1], W[i]);
    }

    rep(i, n) {
        ans = max(ans, X[i]);
        ans = max(ans, Z[i]);
    }

    rep(i, n-1) {
        ans = max(X[i] + W[n - 2 - i],ans);
        ans = max(Y[i] + Z[n - 2 - i], ans);
    }

    cout << ans << endl;

}