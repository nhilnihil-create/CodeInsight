#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cout << setprecision(4) << setiosflags(ios::fixed); // printf("%.4f", x);

    int n;
    cin >> n;

    vector<int> t(n), v(n);
    for (int i = 0; i < n; ++i) cin >> t[i];
    for (int i = 0; i < n; ++i) { cin >> v[i]; v[i] *= 2; }

    int T = 2 * accumulate(t.begin(), t.end(), 0);
    vector<int> ub(T + 1, INT_MAX / 2);

    int x = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < t[i]; ++j) {
            ub[x] = min(ub[x], v[i]);
            ub[x + 1] = min(ub[x + 1], v[i]);
            ub[x + 2] = min(ub[x + 2], v[i]);
            x += 2;
        }
    }

    ub[0] = ub[T] = 0.0;
    for (int i = 1; i < T; ++i) ub[i] = min(ub[i], ub[i - 1] + 1);
    for (int i = T - 1; 0 < i; --i) ub[i] = min(ub[i], ub[i + 1] + 1);

    double len = 0.0;
    for (int i = 1; i <= T; ++i)
        len += max(ub[i - 1], ub[i]) - (ub[i - 1] == ub[i] ? 0.0 : 0.5);

    cout << 0.25 * len << endl;

    return 0;
}
