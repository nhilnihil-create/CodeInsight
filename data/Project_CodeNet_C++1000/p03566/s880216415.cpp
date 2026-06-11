#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cout << setprecision(4) << setiosflags(ios::fixed); // printf("%.4f", x);

    int n;
    cin >> n;
    vector<double> t(n + 1), v(n + 1);
    for (int i = 1; i <= n; ++i) cin >> t[i];
    for (int i = 1; i <= n; ++i) cin >> v[i];
    for (int i = 1; i <= n; ++i) t[i] += t[i - 1];

    int T = 2 * t[n];
    vector<double> ub(T + 1, 200);
    ub[0] = ub[T] = 0.0;
    for (int i = 0; i <= T; ++i) {
        double cur = 0.5 * i;
        for (int j = 1; j <= n; ++j) {
            if (t[j] == cur) {
                ub[i] = min(ub[i], v[j]);
                if (j + 1 <= n) ub[i] = min(ub[i], v[j + 1]);
                break;
            }
            else if (t[j - 1] < cur && cur < t[j]) {
                ub[i] = min(ub[i], v[j]);
                break;
            }
        }
    }

    for (int i = 1; i < T; ++i)
        ub[i] = min(ub[i], ub[i - 1] + 0.5);
    for (int i = T - 1; 0 < i; --i)
        ub[i] = min(ub[i], ub[i + 1] + 0.5);

    double len = 0.0;
    for (int i = 1; i <= T; ++i) {
        if (ub[i - 1] == ub[i]) len += 0.5 * ub[i];
        else if (ub[i - 1] < ub[i]) len += 0.5 * ub[i - 1] + 0.125;
        else len += 0.5 * ub[i] + 0.125;
    }

    cout << len << endl;

    return 0;
}
