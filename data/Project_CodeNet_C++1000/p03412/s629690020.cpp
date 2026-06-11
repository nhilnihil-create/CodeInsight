#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define endl "\n"

const ll INF = 1e15;
const int MOD = 1e9 + 7;
const double EPS = 1e-7;
const double PI = acos(-1.0);

const int N = 2e5 + 5;

ll n, a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; ++i) 
        cin >> a[i];

    for (int i = 0; i < n; ++i)
        cin >> b[i];

    ll ans = 0;
    for (ll T = 1; T < (1ll << 30); T <<= 1) {
        vector<ll> curA(n), curB(n);

        for (int i = 0; i < n; ++i)
            curA[i] = a[i] % (2 * T);

        for (int i = 0; i < n; ++i)
            curB[i] = b[i] % (2 * T);

        sort(curB.begin(), curB.end());

        ll cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += upper_bound(curB.begin(), curB.end(), 2 * T - 1 - curA[i]) - lower_bound(curB.begin(), curB.end(), T - curA[i]);
            cnt += upper_bound(curB.begin(), curB.end(), 4 * T - 1 - curA[i]) - lower_bound(curB.begin(), curB.end(), 3 * T - curA[i]);
        }

        if (cnt & 1)
            ans += T;
    }

    cout << ans << endl;
}
