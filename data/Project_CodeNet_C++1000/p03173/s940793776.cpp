#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

vector<vector<ll> > dp;

ll sum(int l, int r, ll *s) {
    if (l == 0)
        return s[r];

    return s[r]-s[l-1];
}

ll func(int l, int r, ll *s) {
    if (l == r)
        return dp[l][r] = 0;
    if (dp[l][r] != -1)
        return dp[l][r];

    ll ans = 1e18;
    for (int i = l; i < r; i++) {
        ans = min(ans, sum(l, i, s)+sum(i+1, r, s)+func(l, i, s)+func(i+1, r, s));
    }

    return dp[l][r] = ans;
}

int main() {
    int n;  cin >> n;
    ll *a = new ll[n], *s = new ll[n];
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    dp.resize(n, vector<ll>(n, -1));

    s[0] = a[0];
    for (int i = 1; i < n; i++)
        s[i] = s[i-1] + a[i];

    cout << func(0, n-1, s) << endl;

    return 0;
}