#include<bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)n; ++i)
#define FOR(i, a, b) for(int i = a; i < (int)b; ++i)

using ll = long long;

const int Inf = 1e9;
const double EPS = 1e-9;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    ll m, res = 0;
    cin >> n >> m;
    vector<ll> a(n + 1);
    map<ll, int> mp;
    rep (i, n) cin >> a[i + 1];
    FOR (i, 1, n + 1) {
        a[i] += a[i - 1];
        a[i] %= m;
    }
    rep (i, n + 1) {
        res += mp[a[i]];
        mp[a[i]]++;
    }
    cout << res << endl;

    return 0;
}

