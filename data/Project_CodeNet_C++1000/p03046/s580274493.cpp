#include<bits/stdc++.h>

using namespace std;
using ll = long long int;

int main(void) {
    constexpr ll MOD = 1e9 + 7;
    cout << fixed << setprecision(16);

    ll m, k;
    cin >> m >> k;

    if(m==1 && k==1 || (k >= 1ll<<m)) {
        cout << -1 << endl;
        return 0;
    }
    if(m==1 && k==0) {
        cout << "1 1 0 0" << endl;
        return 0;
    }

    vector<ll> v(2ll<<m);
    {
        ll j = 0;
        for(ll i=0; i<1ll<<m; i++)
            if(i != k)
                v[j++] = i;
        v[j++] = k;
        for(ll i=(1ll<<m)-1; i>=0; i--)
            if(i != k)
                v[j++] = i;
        v[j++] = k;
    }
    for(auto &e: v) cout << e << ' ';
    cout << endl;

}
