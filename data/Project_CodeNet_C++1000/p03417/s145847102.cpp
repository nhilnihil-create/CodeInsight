#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int mod = 1e9+7;
const int INF = 1e9;
const int MAX = 1e6;

ll solve(ll n, ll m) {
    ll r = (n-2) * (m-2);
    if (r < 0) r *= -1;
    return r;
}

int main() {
    ll n, m;
    cin >> n >> m;
    cout << solve(n, m) << endl;
}
