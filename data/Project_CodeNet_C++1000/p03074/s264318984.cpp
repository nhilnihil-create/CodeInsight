#include <bits/stdc++.h>

#define EPS (1e-10)
#define rep(i, a, b) for (int i = a; i < (int)(b); ++i)
#define rrep(i, a, b) for (int i = b - 1; i >= (int)(a); --i)
#define all(a) a.begin(), a.end()

using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvb = vector<vb>;

constexpr int MOD = 1000000007;

bool check(const vi& l, const vi& r, int mid, int k) {
    rep(i, 0, (int)l.size() - mid + 1) {
        int start = l[i], end = r[i + mid - 1];
        if (end - start <= k) { return true; }
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int cnt = 0;
    vi l(n, 0), r(n, 0);
    if (s[0] == '1') { ++cnt; }

    rep(i, 1, n) {
        if (s[i] == '1' && s[i - 1] == '0') { ++cnt; }
        if (s[i] == '1') {
            l[i] = r[i] = cnt;
        } else {
            l[i] = cnt;
            r[i] = cnt + 1;
        }
    }
    if (s[0] == '1') {
        l[0] = r[0] = 1;
    } else {
        l[0] = 0;
        r[0] = cnt > 0 ? 1 : 0;
    }

    int ok = 1, ng = n + 1;
    while (ok + 1 < ng) {
        int mid = (ok + ng) / 2;
        if (check(l, r, mid, k)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    cout << ok << endl;

    return 0;
}