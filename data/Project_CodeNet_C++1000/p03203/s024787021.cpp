#include<bits/stdc++.h>

using namespace std;
using ll = long long int;
#define long ll

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);

    ll h, w, n;
    cin >> h >> w >> n;

    vector<pair<ll,ll>> v(n);
    for(ll i=0; i<n; i++) {
        ll x, y;
        cin >> x >> y;
        x--, y--;
        v[i] = make_pair(x, y);
    }
    sort(v.begin(), v.end());

    ll r = h;
    {
        ll t = 0;
        for(ll i=0; i<n; i++) {
            ll x, y;
            tie(x, y) = v[i];
            if(x - y == t) t++;
            else if(x - y > t) {
                r = min(r, x);
            }
        }
    }

    cout << r << endl;

}
