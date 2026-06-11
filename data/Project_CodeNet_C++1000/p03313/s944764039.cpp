#include<bits/stdc++.h>

using namespace std;
using ll = long long int;
#define long ll

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    ll nn = 1ll<<n;

    vector<ll> a(nn);
    for(auto &e: a) cin >> e;

    using P = pair<ll, ll>;
    P z = P(-1, -1);

    vector<ll> r(nn, 0);
    r[0] = a[0];

    vector<P> m1(nn, z), m2(nn, z);
    m1[0] = P(a[0], 0);
    for(ll k=1; k<nn; k++) {
        P mm1 = z, mm2 = z;
        for(ll i=0; i<20; i++) {
            ll j = k & ~(1ll<<i);
            if(k == j) continue;

            for(auto &t: {m1[j], m2[j]}) {
                if(t.second == mm1.second || t.second == mm2.second) continue;
                if(t.first > mm1.first)
                    mm2 = mm1, mm1 = t;
                else if(t.first > mm2.first)
                    mm2 = t;
            }
        }
        if(a[k] > mm1.first)
            mm2 = mm1, mm1 = P(a[k], k);
        else if(a[k] > mm2.first)
            mm2 = P(a[k], k);
        m1[k] = mm1;
        m2[k] = mm2;
        r[k] = max(r[k-1], mm1.first + mm2.first);
    }

    for(ll k=1; k<nn; k++)
        cout << r[k] << endl;
}
