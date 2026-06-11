#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define P pair<ll, ll>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl
#define coel cout << endl
#define pb push_back
#define sz(v) ((int)(v).size())
using namespace std;  
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;


////////////////////////////////////////////////////////


int main() {
    ll n, m; cin >> n >> m;
    Vp p(m);
    rep(i, 0, m){
        ll a, b; cin >> a >> b;
        p[i].first = b; p[i].second = a;
    }
    sort(ALL(p));
    Vl v = {};
    rep(i, 0, m){
        ll a = p[i].second, b = p[i].first;
        bool f = false;
        rep(j, 0, sz(v)){
            if(a < v[j] && v[j] <= b) f = true;
        }
        if(f) continue;
        v.push_back(b);
    }
    ll ans = sz(v);
    co(ans);

    return 0;
}
