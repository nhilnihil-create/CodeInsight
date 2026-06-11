#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int N, C;
    cin >> N >> C;
    vec<int> s(N), t(N), c(N);
    rep(i, N) cin >> s[i] >> t[i] >> c[i];

    vec<vec<int>> imos(31, vec<int>(2 * 1e5 + 20, 0));
    rep(i, N) {
        ++imos[c[i]][s[i] * 2 - 1];
        --imos[c[i]][t[i] * 2];
    }

    int ans = 0;
    for (int i = 1; i <= 2 * 1e5 + 10; ++i) {
        int sm = 0;
        rep(j, 31) {
            imos[j][i] = imos[j][i - 1] + imos[j][i];
            if(imos[j][i]>=1) ++sm;
        }
        ans = max(ans,sm);
    }
    cout << ans << endl;
}