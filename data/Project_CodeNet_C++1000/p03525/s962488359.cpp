#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll n;
    cin >> n;
    vector<ll> d(n);
    rep(i, n) cin >> d[i];
    map<ll, ll> cnt;
    rep(i, n) cnt[d[i]]++;
    cnt[0]++;
    ll ans1 = LONG_LONG_MAX;
    for(auto x : cnt) {
        if (x.second >= 3) {
            cout << 0 << endl;
            return 0;
        }
        if (x.second == 2) {
            ans1 = min(ans1, x.first);
            ans1 = min(ans1, 24 - x.first * 2);
        }
    }
    ll ans2 = LONG_LONG_MIN;
    if ((cnt[0] >= 2) || (cnt[12] >= 2)) {
        cout << 0 << endl;
        return 0;
    }
    rep(i, 1LL << 13) {
        ll dist = LONG_LONG_MAX;
        rep(ii, 13) {
            rep(iii, 13) {
                if ((ii == iii) || (cnt[ii] == 0) || (cnt[iii] == 0)) continue;
                if ((cnt[ii] == 1) && (cnt[iii] == 1)) {
                    ll d1 = ((i & (1LL << ii)) == 0) ? ii : (24 - ii);
                    ll d2 = ((i & (1LL << iii)) == 0) ? iii : (24 - iii);
                    dist = min(dist, min(abs(d1 - d2), 24 - abs(d1 - d2)));
                }
                else if (cnt[ii] == 2) {
                    ll d1 = ((i & (1LL << iii)) == 0) ? iii : (24 - iii);
                    dist = min(dist, min(abs(d1 - ii), 24 - abs(d1 - ii)));
                    dist = min(dist, min(abs(d1 - (24 - ii)), 24 - abs(d1 - (24 - ii))));
                }
                else if (cnt[iii] == 2) {
                    ll d1 = ((i & (1LL << ii)) == 0) ? ii : (24 - ii);
                    dist = min(dist, min(abs(d1 - iii), 24 - abs(d1 - iii)));
                    dist = min(dist, min(abs(d1 - (24 - iii)), 24 - abs(d1 - (24 - iii))));
                }
                else {
                    dist = min(dist, min(abs(ii - iii), 24 - abs(ii - iii)));
                    dist = min(dist, min(abs(ii - (24 - iii)), 24 - abs(ii - (24 - iii))));
                    dist = min(dist, min(abs((24 - ii) - iii), 24 - abs((24 - ii) - iii)));
                    dist = min(dist, min(abs((24 - ii) - (24 - iii)), 24 - abs((24 - ii) - (24 - iii))));
                }
            }
        }
        if (dist != LONG_LONG_MAX) ans2 = max(ans2, dist);
    }
    cout << min(ans1, ans2) << endl;
    return 0;
}
