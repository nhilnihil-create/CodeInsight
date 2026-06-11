#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

vector<ll> s, t, x;

ll s_left_dist(ll key) {
    ll tar = s[lower_bound(all(s), key) - s.begin() - 1];
    return abs(key - tar);
}

ll s_right_dist(ll key) {
    ll tar = *upper_bound(all(s), key);
    return abs(tar - key);
}

ll t_left_dist(ll key) {
    ll tar = t[lower_bound(all(t), key) - t.begin() - 1];
    return abs(key - tar);
}

ll t_right_dist(ll key) {
    ll tar = *upper_bound(all(t), key);
    return abs(tar - key);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B, Q;
    cin >> A >> B >> Q;
    s.resize(A), t.resize(B), x.resize(Q);

    rep(i, A) { cin >> s[i]; }

    rep(i, B) { cin >> t[i]; }

    s.push_back(-INF), s.push_back(INF);
    t.push_back(-INF), t.push_back(INF);

    sort(all(s)), sort(all(t));

    rep(i, Q) {
        cin >> x[i];
        ll tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, sl, sr, tl, tr, ans = INF;
        sl = s_left_dist(x[i]);
        sr = s_right_dist(x[i]);
        tl = t_left_dist(x[i]);
        tr = t_right_dist(x[i]);

        tmp1 = max(sl, tl);
        ans = min(ans, tmp1);
        tmp2 = max(sr, tr);
        ans = min(ans, tmp2);

        ll key3 = x[i] - sl;
        tmp3 = sl + t_right_dist(key3);
        ans = min(ans, tmp3);
        ll key4 = x[i] + sr;
        tmp4 = sr + t_left_dist(key4);
        ans = min(ans, tmp4);
        ll key5 = x[i] - tl;
        tmp5 = tl + s_right_dist(key5);
        ans = min(ans, tmp5);
        ll key6 = x[i] + tr;
        tmp6 = tr + s_left_dist(key6);
        ans = min(ans, tmp6);

        cout << ans << endl;
    }
}