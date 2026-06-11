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

ll modpow(ll a, ll b){
    ll re = 1;
    while(b){
        re *= a;
        re %= MOD;
        b--;
    }
    return re;
}

int main() {
    ll n; cin >> n;
    string s; cin >> s;
    map<char, ll> ma;
    rep(i, 0, n){
        ma[s[i]]++;
    }
    ll ans = 1;
    for(auto c : ma){
        ans *= (c.second+1)%MOD;
        ans %= MOD;
    }
    if(ans - 1 < 0) ans += MOD;
    co(ans - 1);

    return 0;
}
