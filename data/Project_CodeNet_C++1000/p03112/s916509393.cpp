#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repr(i, a, b) for (int i=a; i<(b); ++i)
#define reprev(i, n) for (int i=n-1; i>=0; --i)
#define reprrev(i, a, b) for (int i=b-1; i>=(a); --i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<ll> s, t, x;

pair<ll, ll> bin_ss(ll p) {
    int l = 0, r = s.size() - 1;
    while (l + 1 < r) {
        int c = (l + r) / 2;
        if (s[c] <= p) {
            l = c;
        } else {
            r = c;
        }
    }
    return make_pair(l, r);
}

pair<ll, ll> bin_st(ll p) {
    int l = 0, r = t.size() - 1;
    while (l + 1 < r) {
        int c = (l + r) / 2;
        if (t[c] <= p) {
            l = c;
        } else {
            r = c;
        }
    }
    return make_pair(l, r);
}

int main() {
    cout << fixed << setprecision(10);
    
    int A, B, Q; cin >> A >> B >> Q;

    // vector<ll> s(A), t(B), x(Q);
    s.resize(A);
    t.resize(B);
    x.resize(Q);

    rep(i, A) cin >> s[i];
    rep(i, B) cin >> t[i];
    rep(i, Q) cin >> x[i];

    s.emplace_back(1e12);
    s.emplace_back(-1e12);
    t.emplace_back(1e12);
    t.emplace_back(-1e12);

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    // Qごとに、左右の最短の神社寺に行ったときに最小の距離を算出する (2 * 2) / per q 
    rep(i, Q) {
        ll ans = 1e12;
        auto sp = bin_ss(x[i]);
        auto tp = bin_st(x[i]);
        // 神社探索
        // 左
        ll s_init;
        if (sp.first != 0) {
            s_init = s[sp.first];
            ll tans = 0;
            tans += abs(x[i] - s_init);
            auto tp_s = bin_st(s_init);
            tans += min(abs(s_init - t[tp_s.first]), abs(s_init - t[tp_s.second]));
            ans = min(ans, tans);
        }
        // 右
        if (sp.second != s.size() - 1) {
            s_init = s[sp.second];
            ll tans = 0;
            tans += abs(x[i] - s_init);
            auto tp_s = bin_st(s_init);
            tans += min(abs(s_init - t[tp_s.first]), abs(s_init - t[tp_s.second]));
            ans = min(ans, tans);
        }
        // 寺探索
        // 左
        ll t_init;
        if (tp.first != 0) {
            t_init = t[tp.first];
            ll tans = 0;
            tans += abs(x[i] - t_init);
            auto sp_t = bin_ss(t_init);
            tans += min(abs(t_init - s[sp_t.first]), abs(t_init - s[sp_t.second]));
            ans = min(ans, tans);
        }
        // 右
        if (tp.second != t.size() - 1) {
            t_init = t[tp.second];
            ll tans = 0;
            tans += abs(x[i] - t_init);
            auto sp_t = bin_ss(t_init);
            tans += min(abs(t_init - s[sp_t.first]), abs(t_init - s[sp_t.second]));
            ans = min(ans, tans);
        }

        cout << ans << endl;
    }
    return 0;
}