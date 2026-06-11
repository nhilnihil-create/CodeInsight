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
    ll H, W;
    cin >> H >> W;

    vector<ll> a(H * W);
    rep(i, H * W) cin >> a[i];

    // じぐざくに一筆書き
    typedef pair<ll, ll> P;
    vector<P> b;
    rep(y, H) rep(x, W) {
        if (y % 2 == 0) {
            b.push_back(P(x, y));
        }
        else {
            b.push_back(P(W - 1 - x, y));
        }
    }

    vector<ll> res;
    rep(i, b.size() - 1) {
        ll index = b[i].first + b[i].second * W;
        ll index2 = b[i+1].first + b[i+1].second * W;
        if (a[index] % 2 != 0) {
            res.push_back(1+b[i].second);
            res.push_back(1+b[i].first);
            res.push_back(1+b[i+1].second);
            res.push_back(1+b[i+1].first);
            // cout << (1+b[i].second) << " " << (1+b[i].first) << " ";
            // cout << (1+b[i+1].second) << " " << (1+b[i+1].first) << endl;
            a[index]--;
            a[index2]++;
        }
    }

    put(res.size() / 4);
    rep(i, res.size() / 4) {
        cout << res[4*i+0] << " " << res[4*i+1] << " " << 
                res[4*i+2] << " " << res[4*i+3] << endl;
    }
}
signed main(){ Main();return 0;}