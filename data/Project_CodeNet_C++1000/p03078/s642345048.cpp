//----------------------------------------------------------------------
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
//----------------------------------------------------------------------

using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(void) {
    ll x, y, z, k;
    cin >> x >> y >> z >> k;
    vector<ll> a(x);
    rep(i, x) cin >> a[i];
    vector<ll> b(y);
    rep(i, y) cin >> b[i];
    vector<ll> c(z);
    rep(i, z) cin >> c[i];

    sort(c.rbegin(), c.rend());

    vector<ll> ab;

    rep(i,x)
    rep(j,y) {
        ab.push_back(a[i] + b[j]);
    }

    sort(ab.rbegin(), ab.rend());

    vector<ll> abc;

    ll n = min(k, (ll)ab.size());
    ll n2 = min(k, (ll)c.size());
    rep(i, n) {
        rep(j, n2) {
            abc.push_back(ab[i] + c[j]);
        }
    }

    sort(abc.rbegin(), abc.rend());

    rep(i, k) {
        cout << abc[i] << endl;
    }

    return 0;
}
