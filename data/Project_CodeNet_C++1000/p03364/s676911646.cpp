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
    cin >> n;
    char A[n][n], B[n][n];

    rep(i, n) {
        rep(j, n) {
            cin >> A[i][j];
        }
    }

    rep(_, n) {
        rep(i, n) {
            rep(j, n) {
                B[i][j] = A[i][(j + _) % n];
            }
        }

        k = 1;
        rep(i, n) {
            rep(j, i) {
                if (B[i][j] != B[j][i])k = 0;
            }
        }

        ans += k;
    }

    cout << ans * n << endl;
}
