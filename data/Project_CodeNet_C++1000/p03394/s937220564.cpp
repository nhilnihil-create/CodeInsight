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
    int n;
    cin >> n;
    if (n == 3) {
        cout << "2 5 63" << endl;
        return 0;
    }
    if (n == 4) {
        cout << "2 5 20 63" << endl;
        return 0;
    }
    if (n == 5) {
        cout << "2 3 4 6 9" << endl;
        return 0;
    }
    if (n == 6) {
        cout << "2 3 4 6 9 12" << endl;
        return 0;
    }
    if (n == 7) {
        cout << "2 3 4 6 9 12 18" << endl;
        return 0;
    }

    vector<int> ans = {2, 3, 4, 6, 8, 9, 10, 12};
    int k = 2;
    for (; 8 * k <= n; k++) {
        rep(i, 12) {
            if (i % 2 == 0 || i % 3 == 0) {
                ans.push_back(12 * k - i);
            }
        }
    }
    if (n % 8 == 1) {
        ans.insert(ans.end(), {12 * k});
    }
    if (n % 8 == 2) {
        ans.insert(ans.end(), {12 * k - 9, 12 * k - 3});
    }
    if (n % 8 == 3) {
        ans.insert(ans.end(), {12 * k - 9, 12 * k - 3, 12 * k});
    }
    if (n % 8 == 4) {
        ans.insert(ans.end(),
                   {12 * k - 9, 12 * k - 3, 12 * k - 10, 12 * k - 2});
    }
    if (n % 8 == 5) {
        ans.insert(ans.end(),
                   {12 * k - 9, 12 * k - 3, 12 * k - 10, 12 * k - 2, 12 * k});
    }
    if (n % 8 == 6) {
        ans.insert(ans.end(), {12 * k - 9, 12 * k - 3, 12 * k - 10, 12 * k - 2,
                               12 * k - 4, 12 * k - 8});
    }
    if (n % 8 == 7) {
        ans.insert(ans.end(), {12 * k - 9, 12 * k - 3, 12 * k - 10, 12 * k - 2,
                               12 * k - 4, 12 * k - 8, 12 * k});
    }

    sort(all(ans));
    rep(i, n) cout << ans[i] << " \n"[i == n - 1];
}
