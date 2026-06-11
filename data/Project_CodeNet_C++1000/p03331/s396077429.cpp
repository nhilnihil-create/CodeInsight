#include <bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define l first
#define r second
#define all(x) x.begin(), x.end()
#define int long long

const int maxn = 5e5 + 1;

using namespace std;

int n;
string s;

int ds(int x) {
    int ans = 0;
    while (x) {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int ans = 1e18;
    for (int a = 1; a < n; a++) {
        int b = n - a;
        ans = min(ans, ds(a) + ds(b));
    }
    cout << ans;
    return 0;
}
