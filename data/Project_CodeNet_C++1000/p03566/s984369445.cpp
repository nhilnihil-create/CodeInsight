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
    ll n;
    cin >> n;

    vector<ll> t(n);
    rep(i, n) cin >> t[i];
    
    vector<ll> v(n);
    rep(i, n) cin >> v[i];
    
    ll S = 0;
    rep(i, n) {
        S += v[i] * t[i];
    }

    // 0.5sec単位での速度を求めていく

    ll total = accumulate(all(t), 0LL);

    ld INF = 1e18;
    vector<ld> V(total * 2 + 1, INF);

    ll now = 0;
    rep(i, n) {
        rep(dt, t[i]) {
            ll t1 = now + 2 * dt; 
            ll t2 = now + 2 * dt + 1; 
            V[t1] = min(V[t1], (ld)v[i]);
            V[t2] = min(V[t2], (ld)v[i]);
        }
        now += t[i] * 2;
        V[now] = min(V[now], (ld)v[i]);
    }

    // 両端は0
    V[0] = 0;
    V[2 * total] = 0;

    // 前から速度をあげれるだけ上げたときの制約
    for (ll i = 1; i < V.size(); i++) {
        V[i] = min(V[i], V[i-1] + 0.5);
    }

    // 後ろから速度をあげれるだけ上げたときの制約
    for (ll i = V.size() - 2; i >= 0; i--) {
        V[i] = min(V[i], V[i+1] + 0.5);
    }

    ld res = 0;
    rep(i, V.size()-1) {
        res += (V[i] + V[i+1]) * 0.5 / 2;
    }
    printf("%.12Lf\n", res);
}
signed main(){ Main();return 0;}