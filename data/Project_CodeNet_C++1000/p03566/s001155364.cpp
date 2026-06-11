#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using piii = pair<pair<int, int>, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using uint = unsigned int;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;
const ld PI = acosl(-1);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> t(N), v(N);
    for (int i = 0; i < N; ++i)
        cin >> t[i];
    for (int i = 0; i < N; ++i)
        cin >> v[i];

    vector<int> nv(N + 1);
    nv[N] = 0;
    for (int i = N - 1; i > 0; --i) {
        nv[i] = min(v[i], nv[i + 1] + t[i]);
        nv[i] = min(nv[i], v[i - 1]);
    }

    int nowv = 0;
    ld ans = 0;
    for (int i = 0; i < N; ++i) {
        if (nowv + t[i] <= nv[i + 1]) {
            ans += (ld)(2 * nowv + t[i]) * t[i] / 2;
            nowv += t[i];
        } else {
            ld tmp = (ld)(nv[i + 1] - nowv + t[i]) / 2;
            ld ma = nowv + tmp;
            ans += (nowv + ma) * tmp / 2;
            ans += (nv[i + 1] + ma) * (t[i] - tmp) / 2;
            if (ma > v[i]) {
                int d = t[i] - (2 * v[i] - nowv - nv[i + 1]);
                ans -= d * (ma - v[i]) / 2;
            }
            nowv = nv[i + 1];
        }
    }

    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}
