#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cnt[p[i]] = cnt[p[i] - 1] + 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, cnt[i]);
    }
    ans = n - ans;
    cout << ans << endl;
    return 0;
}
