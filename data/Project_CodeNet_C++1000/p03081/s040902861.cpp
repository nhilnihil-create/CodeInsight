#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
#define get_unique(x) x.erase(unique(all(x)), x.end());
typedef long long ll;
typedef complex<double> Complex;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll LINF = 1e18;
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<char> t(q), d(q);
    rep(i, q) cin >> t[i] >> d[i];

    int lok = n, lng = -1, lmid;
    while (lok - lng > 1) {
        lmid = (lok + lng) / 2;
        int pos = lmid;
        bool f = true;
        rep(i, q) {
            if (s[pos] == t[i]) {
                if (d[i] == 'L') pos--;
                if (d[i] == 'R') pos++;
            }
            if (pos < 0) {
                f = false;
                break;
            }
            if (pos >= n) {
                break;
            }
        }
        (f ? lok : lng) = lmid;
    }

    int rok = -1, rng = n, rmid;
    while (rng - rok > 1) {
        rmid = (rok + rng) / 2;
        int pos = rmid;
        bool f = true;
        rep(i, q) {
            if (s[pos] == t[i]) {
                if (d[i] == 'L') pos--;
                if (d[i] == 'R') pos++;
            }
            if (pos >= n) {
                f = false;
                break;
            }
            if (pos < 0) {
                break;
            }
        }
        (f ? rok : rng) = rmid;
    }
    // cout << lok << " " << rok << endl;
    cout << max(0, rok - lok + 1) << endl;
}
