#include <bits/stdc++.h>
using namespace std;

#define rep(i, j) for (int i = 0; i < j; i++)
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<pii> vpii;

ll check1(const vll& a, ll x) {
    rep(i, a.size()) {
        x -= x % a[i];
    }
    return x;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int k;
    cin >> k;
    vll a(k);
    rep(i, k) cin >> a[i];

    ll lo = 1, hi = (1LL << 60);
    while (hi - lo > 1) {
        ll mid = lo + (hi - lo) / 2;
        ll x = check1(a, mid);
        if (x >= 2) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    if (check1(a, hi) != 2) {
        cout << -1 << endl;
        return 0;
    }
    ll ansh = hi;

    lo = 2, hi = (1LL << 60);
    while (hi - lo > 1) {
        ll mid = lo + (hi - lo) / 2;
        ll x = check1(a, mid);
        if (x <= 2) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    // cout << lo << " " << hi << endl;

    cout << ansh <<  " " << lo << endl;

    return 0;
}
