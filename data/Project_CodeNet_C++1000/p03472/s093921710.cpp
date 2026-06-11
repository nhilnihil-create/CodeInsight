#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define reprr(i, m, n) for (ll i = m; i < n; i++)
#define inf 2e9
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
using Graph = vector<vector<pair<ll, ll>>>;


int main()
{
    ll N, H; cin >> N >> H;
    vll a(N), b(N);
    ll sum = 0;
    ll amax = 0;
    rep(i, N) cin >> a[i] >> b[i], amax = max(amax, a[i]), sum += b[i];
    sort(all(b));
    reverse(all(b));
    ll count = 0;
    rep(i, N) {
        if (b[i] < amax) break;
        H -= b[i];
        count++;

        if (H <= 0) {
            cout << count << endl;
            return 0;
        }
    }

    count += (H + amax - 1) / amax;
    cout << count << endl;

    return 0;
}