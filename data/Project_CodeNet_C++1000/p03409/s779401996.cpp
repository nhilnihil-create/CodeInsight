#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define inf LLONG_MAX
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;


int main()
{
    ll n; cin >> n;
    vector<pair<ll, ll>> reds(n);
    rep(i, n) {
        ll a, b; cin >> a >> b;
        reds[i] = make_pair(a, b);
    }
    vector<pair<ll, ll>> blues(n);
    rep(i, n) {
        ll c, d; cin >> c >> d;
        blues[i] = make_pair(c, d);
    }
    sort(all(blues));
    ll count = 0;
    vector<bool> used(n, false);
    rep(i, n) {
        auto blue = blues[i];
        ll max_y = -inf;
        ll max_index = -1;
        for (ll j = n-1; j >= 0; j--) {
            auto red = reds[j];
            if (used[j]) continue;
            if (red.first < blue.first) {
                if (red.second < blue.second && red.second > max_y) {
                    max_y = red.second;
                    max_index = j;
                }
            }
        }

        if (max_y > -inf) {
            count++;
            used[max_index] = true;
        }
    }
    cout << count << endl;
    return 0;
}