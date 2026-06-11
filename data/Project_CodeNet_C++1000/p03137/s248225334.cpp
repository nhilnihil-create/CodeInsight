#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> x(m);
    for (int i = 0; i < m; i++) {
        cin >> x[i];
    }
    int ans = 0;
    if (n < m) {
        vector<int> dif(m - 1);
        sort(x.begin(), x.end());
        for (int i = 0; i < m - 1; i++) {
            dif[i] = abs(x[i + 1] - x[i]);
        }
        sort(dif.begin(), dif.end());
        for (int i = 0; i < m - n; i++) {
            ans += dif[i];
        }
    }
    cout << ans << endl;
    return 0;
}