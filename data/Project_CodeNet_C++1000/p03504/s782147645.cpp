#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
// using namespace atcoder;
void Main()
{
    ll n, C;
    cin >> n >> C;

    vector<ll> s(n), t(n), c(n);
    rep(i, n) cin >> s[i] >> t[i] >> c[i];
    
    vector<ll> S(n), T(n);
    rep(i, n) {
        S[i] = s[i] * 2 - 1;
        T[i] = t[i] * 2;
    }

    ll maxT = *max_element(all(T));
     
    vector<vector<ll>> d(C + 1, vector<ll>(maxT + 1));
    rep (i, n) {
        d[c[i]][S[i]]++;
        d[c[i]][T[i]]--;
    }

    rep (ch, C + 1) {
        repi(i, d[ch].size()) {
            d[ch][i] = d[ch][i-1] + d[ch][i];
        }
    }

    ll res = 0;
    rep(i, d[0].size()) {
        ll v = 0;
        rep (ch, C + 1) {
            if (d[ch][i] > 0) v++;
        }
        res = max(res, v);
    }

    put(res);
}
signed main(){ Main();return 0;}