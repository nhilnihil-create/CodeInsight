#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;

const ll INF = 1LL<<60;

int main() 
{
    int a, b, q;
    cin >> a >> b >> q;
    vector<ll> S(a);
    vector<ll> T(b);
    rep(i,a) cin >> S[i];
    rep(i,b) cin >> T[i];


    auto f = [&](ll x) {
        ll sl = -INF; ll sr = INF;
        ll tl = -INF; ll tr = INF;
        auto itS  = lower_bound(S.begin(), S.end(),x);
        if (itS != S.end()) sr = *itS;
        if (itS - S.begin() > 0) sl = *(--itS);        
        auto itT  = lower_bound(T.begin(), T.end(),x);
        if (itT != T.end()) tr = *itT;
        if (itT - T.begin() > 0) tl = *(--itT);

        auto calc = [&](ll x, ll y) {
            if (x < 0 && y < 0) return abs(min(x, y));
            if (x > 0 && y > 0) return max(x, y);
            return min(abs(x)*2 + abs(y), abs(x) + abs(y)*2);
        };

        ll res = calc(sl-x, tl-x);
        res = min(res, calc(sl-x, tr-x));
        res = min(res, calc(sr-x, tl-x));
        res = min(res, calc(sr-x, tr-x));

       return res;
    };

    rep(i,q) {
        ll x;
        cin >> x;
        cout << f(x) << endl;
    }
    return 0;
}
