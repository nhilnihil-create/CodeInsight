#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
#define ALL(v) v.begin(), v.end()
#define vmax(v) *max_element(ALL(v))
#define vmin(v) *min_element(ALL(v))
#define chmax(x, a) x = max(x, a)
#define chmin(x, a) x = min(x, a)

const ll INF = 2e12;

int main() {
    ll A, B; cin >> A >> B;
    int Q; cin >> Q;
    vector<ll> s(A), t(B);
    rep(i, A) cin >> s[i];
    rep(i, B) cin >> t[i];
    ll x;

    rep(_, Q) {
        cin >> x;

        ll leftS, leftT, rightS, rightT;

        int sx = lower_bound(ALL(s), x) - s.begin();
        int tx = lower_bound(ALL(t), x) - t.begin();

        if (sx > 0) leftS = x-s[sx-1];
        else leftS = INF;
        if (tx > 0) leftT = x-t[tx-1];
        else leftT = INF;

        if (sx < s.size()) rightS = s[sx]-x;
        else rightS = INF;
        if (tx < t.size()) rightT = t[tx]-x;
        else rightT = INF;

        ll ans = min({max(leftS, leftT), max(rightS, rightT),
                2*leftS+rightT, 2*rightT+leftS, 2*leftT+rightS, 2*rightS+leftT});

        cout << ans << endl;
    }
}
