#include <bits/stdc++.h>

#define ll long long
#define MAXN 200005

using namespace std;

ll dp[MAXN], bit[MAXN];

void upd(int x, ll y, int n) {

    for(int i = x; i <= n; i += i & -i)
        bit[i] = max(bit[i], y);
}

ll get(int x) {

    ll ans = 0;
    for(int i = x; i > 0; i -= i & -i)
        ans = max(ans, bit[i]);
    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int h[n];
    for(int i = 0; i < n; i++)
        cin >> h[i];
    ll a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    for(int i = 0; i < n; i++) {
        dp[i] = get(h[i] - 1) + a[i];
        upd(h[i], dp[i], n);
    }

    ll ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}
