#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> PP;
#define rep(i, n) for(ll i = 0; i < ll(n); i++)
#define rrep(i, n) for(ll i = n - 1; i > -1; i--)
#define all(v) v.begin(), v.end()
#define pb push_back
#define fi first
#define se second
#define debug(V) rep(i, V.size()) cout << V[i] << " ";
const ll INF = 1LL << 61;
const ll MOD = 1000000007 /*988244353*/;
const ll MAX_N = 500010;
ll a, b, c, d, e, f, h, x, y, z, p, q, m, n, t, r, k, w, l, ans, i, j;
string S, T;
vl A, B;
void solve() {
    n = S.length();
    rep(i, n) {
        vl A(26, 0), B(26, 0);
        rep(j, n) {
            a = 0;
            if(j <= i)
                A[S[j] - 'a']++;
            else
                B[S[j] - 'a']++;
        }

        rep(j, 26) {
            if(A[j] * B[j])
                a++;
        }
        ans = max(ans, a);
    }

    cout << ans << endl;
}
int main() {
    // cout<<fixed<<setprecision(15);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> S;
    solve();
}