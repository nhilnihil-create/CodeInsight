#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1000000000 + 7;

int main() {
    int n;
    cin >> n;
    const int m = 5;
    vector<ll> cnt(m, 0);
    string march = "MARCH";
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[0] == march[j]) cnt[j]++;
        }
    }
    ll ans = 0;
    for (int i = 0; i < m - 2; i++) {
        for (int j = i + 1; j < m - 1; j++) {
            for (int k = j + 1; k < m; k++) {
                ans += cnt[i] * cnt[j] * cnt[k];
            }
        }
    }
    cout << ans << endl;
    return 0;
}