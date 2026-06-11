#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define P pair<ll, ll>
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl
#define coel cout << endl
#define pb push_back
#define sz(v) ((ll)(v).size())
using namespace std;  
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define pp pair<ll, pair<ll, ll>> 




////////////////////////////////////////////////////////


int main() {
    ll n; cin >> n;
    ll now = 0;
    map<ll, ll> ma;
    ma[0]++;
    rep(i, 0, n){
        ll a; cin >> a;
        now += a;
        ma[now]++;
    }
    ll ans = 0;
    for(auto m : ma){
        ll num = m.second;
        ans += (num*(num-1))/2;
    }
    co(ans);

    return 0;
}
