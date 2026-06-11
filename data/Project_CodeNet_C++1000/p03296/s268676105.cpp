#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int ans = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i - 1] == a[i]) {
            ans++;
            a[i] = 0;
        }
    }

    cout << ans << endl;
}