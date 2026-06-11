#include<bits/stdc++.h>

using namespace std;
using ll = long long int;

int main(void) {
    constexpr ll MOD = 1e9 + 7;
    constexpr double PI = acos(-1);
    cout << fixed << setprecision(16);
    cin.tie(0); ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> t(n+1);
    for(ll i=0; i<n+1; i++)
        t[i] = i;

    ll r = 0;
    for(ll i=0; i<n; i++) {
        ll p;
        cin >> p;
        t[p] = t[p-1];
        r = max(r, p - t[p]);
    }
    cout << n-r << endl;
}
