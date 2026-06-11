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

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vll a(n);
    rep(i, n) cin >> a[i];

    if (a[0] != 0) {
        cout << -1 << endl;
        return 0;
    }

    int x = 0;
    rep(i, n) {
        if (x + 1 >= a[i]) x = a[i];
        else {
            cout << -1 << endl;
            return 0;
        }
    }

    ll cur = 0;
    ll ans = 0;
    rep(i, n) {
        if (cur + 1 == a[i]) {
            ans += 1;
        } else {
            ans += a[i];
        }
        // cout << i << " " << cur << " " << ans << endl;
        cur = a[i];
    }

    cout << ans << endl;
    return 0;
}
