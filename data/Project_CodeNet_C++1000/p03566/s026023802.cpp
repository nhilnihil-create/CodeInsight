#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, t[102] = {}, v[102] = {}, d[40404][222] = {};
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> t[i], t[i] += t[i], t[i] += t[i - 1];
    for (int i = 1; i <= n; i++) cin >> v[i], v[i] += v[i];
    for (int i = 0; i <= 40400; i++) for (int j = 0; j <= 213; j++) d[i][j] = -mod;
    d[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = t[i - 1] + 1; j <= t[i]; j++) {
            for (int k = 0; k <= v[i]; k++) {
                d[j][k] = d[j - 1][k] + k + k;
                if (k) d[j][k] = max(d[j][k], d[j - 1][k - 1] + k + k - 1);
                if (j == t[i - 1] + 1) {
                    if (k < v[i]) d[j][k] = max(d[j][k], d[j - 1][k + 1] + k + k + 1);
                } else {
                    d[j][k] = max(d[j][k], d[j - 1][k + 1] + k + k + 1);
                }
            }
        }
    }
    cout << setprecision(13) << d[t[n]][0] / 8.0 << '\n';
}
