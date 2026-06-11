#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define inf 1e9
#define INF 1000000000000000000

int main() {
    int A, B, Q;
    cin >> A >> B >> Q;
    vector<ll> s(A), t(B);
    rep(i, A) { cin >> s[i]; }
    s.push_back(INF), s.push_back(-INF), sort(all(s));

    rep(i, B) { cin >> t[i]; }
    t.push_back(INF), t.push_back(-INF), sort(all(t));

    rep(i, Q) {
        ll x;
        cin >> x;
        ll res = INF;
        ll first1, first2;
        first1 = lower_bound(all(s), x) - s.begin() - 1;
        first2 = upper_bound(all(s), x) - s.begin();
        rep(i, 2) {
            ll second1 = lower_bound(all(t), s[first1]) - t.begin() - 1;
            ll second2 = upper_bound(all(t), s[first1]) - t.begin();
            res =
                min(res, min(abs(x - s[first1]) + abs(s[first1] - t[second1]),
                             abs(x - s[first1]) + abs(s[first1] - t[second2])));
        }

        rep(i, 2) {
            ll second1 = lower_bound(all(t), s[first2]) - t.begin() - 1;
            ll second2 = upper_bound(all(t), s[first2]) - t.begin();
            res =
                min(res, min(abs(x - s[first2]) + abs(s[first2] - t[second1]),
                             abs(x - s[first2]) + abs(s[first2] - t[second2])));
        }

        first1 = lower_bound(all(t), x) - t.begin() - 1;
        first2 = upper_bound(all(t), x) - t.begin();

        rep(i, 2) {
            ll second1 = lower_bound(all(s), t[first1]) - s.begin() - 1;
            ll second2 = upper_bound(all(s), t[first1]) - s.begin();
            res =
                min(res, min(abs(x - t[first1]) + abs(t[first1] - s[second1]),
                             abs(x - t[first1]) + abs(t[first1] - s[second2])));
        }

        rep(i, 2) {
            ll second1 = lower_bound(all(s), t[first2]) - s.begin() - 1;
            ll second2 = upper_bound(all(s), t[first2]) - s.begin();
            res =
                min(res, min(abs(x - t[first2]) + abs(t[first2] - s[second1]),
                             abs(x - t[first2]) + abs(t[first2] - s[second2])));
        }

        cout << res << endl;
    }
}