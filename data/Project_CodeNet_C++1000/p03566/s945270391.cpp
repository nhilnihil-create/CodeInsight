#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, t[102] = {}, v[102] = {}, d[40004][202] = {};
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> t[i], t[i] += t[i], t[i] += t[i - 1];
    for (int i = 1; i <= n; i++) cin >> v[i], v[i] += v[i];
    for (int i = 0; i <= 40000; i++) for (int j = 0; j <= 201; j++) d[i][j] = -mod;
    d[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = t[i - 1] + 1; j <= t[i]; j++) {
            for (int k = 0; k <= v[i]; k++) {
                d[j][k] = d[j - 1][k];
                if (k) d[j][k] = max(d[j][k], d[j - 1][k - 1]);
                if (k < v[i]) d[j][k] = max(d[j][k], d[j - 1][k + 1]);
                d[j][k] += k;
            }
        }
    }
    cout << setprecision(13) << d[t[n]][0] / 4.0 << '\n';
}
