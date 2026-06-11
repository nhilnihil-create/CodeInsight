#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)

using ll = long long; using vll = vector<ll>;

int main(void) {
    ll n; cin >> n;
    string t; cin >> t;
 
    vll l(n+1), r(n+1), in(n+1);
    rep(i, n) {
        l[i+1] = t[i] == 'M';
        r[i+1] = t[i] == 'C';
        in[i+1] = 0;
    }
    rep(i, n) {
        in[i+1] += in[i] + l[i] * r[i+1];
        l[i+1] += l[i];
        r[i+1] += r[i];
    }

    ll q; cin >> q;
    rep(_, q) {
        ll k; cin >> k;
        ll ret = 0;
        rep(i, n) if (t[i] == 'D') {
            ll j = min(n, i+k);
            ret += (-in[i]+r[i]*l[i])+in[j]-l[i]*r[j];
        }
        cout << ret << endl;
    }
 
    return 0;
}
