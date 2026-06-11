#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)

using ll = long long; using vll = vector<ll>;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    ll n; cin >> n;
    string t; cin >> t;
 
    vll l(n+1), r(n+1), in(n+1);
    rep(i, n) {
        l[i+1] = l[i] + (t[i] == 'M');
        r[i+1] = r[i] + (t[i] == 'C');
        in[i+1] = in[i] + l[i] * (t[i] == 'C');
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
