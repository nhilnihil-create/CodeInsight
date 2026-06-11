#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define repr(i, a, b) for(int i = b-1; i >= a; i--)
// #define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
// #define endl "\n"
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
#define fi first
#define se second

////////////////////////////////////////////////////////

// 約数列挙
vector<long long> divisor(long long n){
    vector<long long> div;
    for(long long i = 1; i*i <= n; i++){
        if(n%i == 0){
            div.push_back(i);
            if(i*i != n) div.push_back(n/i);
        }
    }
    sort(div.begin(), div.end());
    return div;
}

int main() {
    ll n; cin >> n;
    Vl div = divisor(n);
    ll ans = 0;
    rep(i, 0, sz(div)){
        ll m = div[i] - 1;
        if(m == 0) continue;
        if(n/m == n%m) ans += m;
    }
    co(ans);

    return 0;
}
 
 
