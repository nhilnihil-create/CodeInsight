#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(int i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(int i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define uniq(x) (x).erase(unique((x).begin(), (x).end()), (x).end())

int solve(ll a, ll b) {
    ll l = 0, r = 1LL << 31, mv = a * b - 1;
    if (a == b) return (2 * a - 2);
    while((l + 1) < r) {
        ll m = (l + r) / 2;
        ll val = ((m + 1) / 2) * ((m + 1) - (m + 1) / 2);
        if (val > mv) {
            r = m;
        }
        else {
            l = m;
        }
    }
    return l - 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int q;
    cin >> q;
    rep(i, q) {
        ll a, b;
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
    return 0;
}
