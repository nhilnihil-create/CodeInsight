#include <bits/stdc++.h>
using namespace std;
  
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

const int N = 1e5 + 5;
ll x[N], val[N], mx[N], pref[N];
ll len;
    int n;

ll solve() {
    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + val[i];
        mx[i] = max(mx[i - 1], pref[i] - x[i] * 2);
    }

    // for (int i = 0; i <= n; i++) {
    //     cout << x[i] << " ";
    // }
    // cout << "\n";

    ll sum = 0;
    for (int i = n; i > 0; i--) {
        sum += val[i];
        ans = max(ans, sum + mx[i - 1] - len + x[i]);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    cin >> n >> len;

    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> val[i];
    }

    ll ans = 0;

    ans = max(solve(), ans);
    reverse(x + 1, x + n + 1);
    for (int i = 1; i <= n; i++) {
        x[i] = len - x[i];
    }
    reverse(val + 1, val + n + 1);
    ans = max(solve(), ans);

    cout << ans << "\n";

    return 0;
}