#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M (ll)1000000007
#define MM (ll)1e8
#define INF (ll)1e18
#define arep(i, x, n) for (long long i = x; i < n; i++)
#define rep(i, n) for (long long i = 0; i < n; ++i)
#define pi 3.141592653589793
#define eps 0.00000001

int main() {
    ll n;
    cin >> n;
    ll t[n];
    ll x[n];
    ll y[n];

    rep(i, n) { cin >> t[i] >> x[i] >> y[i]; }

    ll prevX = 0;
    ll prevY = 0;
    ll prevT = 0;
    bool canGO = true;
    rep(i, n) {
        ll dist = abs(x[i] - prevX) + abs(y[i] - prevY);
        if (dist <= t[i] - prevT && (t[i] - prevT - dist) % 2 == 0) {
            prevX = x[i];
            prevY = y[i];
            prevT = t[i]; 
        } else {
            canGO = false;
            break;
        }
    }

    if (canGO)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}