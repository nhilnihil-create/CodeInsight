#include <bits/stdc++.h>
using namespace std;
template <typename T> using vec = vector<T>;
template <typename T> using vvec = vector<vector<T>>;

constexpr int64_t mpow(int64_t a, int64_t b, int64_t mod = 1000000007) {
    if (b <= 0) { return 1; } if (b == 1) { return a % mod; } if (b == 2) { return (a * a) % mod; }
    return (max(a * (b & 1), (int64_t)1) * mpow(mpow(a, b / 2, mod), 2, mod)) % mod;
}
constexpr int64_t mdiv(int64_t a, int64_t b, int64_t mod = 1000000007) {
    return (a * mpow(b, mod - 2, mod)) % mod;
}

int main() {
    int n; cin >> n;

    int ans = 0, f = 0, m = 0, b = 0;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;

        f += s.front() != 'B' && s.back() == 'A';
        m += s.front() == 'B' && s.back() == 'A';
        b += s.front() == 'B' && s.back() != 'A';

        for (int j = 0; j < s.size() - 1; ++j) {
            ans += s[j] == 'A' && s[j + 1] == 'B';
        }
    }

    if ((f == 0 || b == 0) && m == 0) {
        cout << ans << endl;
        return 0;
    }

    if (f != 0) {
        --f;
        ++ans;
    }
    if (b != 0) {
        --b;
        ++ans;
    }

    ans += m - 1;
    ans += min(f, b);

    cout << ans << endl;
}

