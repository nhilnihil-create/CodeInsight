#include <bits/stdc++.h>
using namespace std;  
#define rep(i, a, b) for(ll i = a; i < b; i++)
#define Rep(i, a, b) for(ll i = a; i <= b; i++)
#define repr(i, a, b) for(ll i = b-1; i >= a; i--)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl
#define coel cout << endl
#define pb push_back
#define sz(v) ((ll)(v).size())
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
// const ll INF = 1LL << 60;
const ll INF = 100000000000;
#define pp pair<ll, pair<ll, ll>> 
// #define fi first
// #define se second
 
/*--------------------------------------------------------------------------------

--------------------------------------------------------------------------------*/

ll b[200005];

int main(){
    ll n; cin >> n;
    Vl p(n);
    rep(i, 0, n) cin >> p[i];

    rep(i, 0, n){
        if(p[i]==1) b[1]++;
        else b[p[i]] = b[p[i]-1]+1;
    }
    ll k = 0;
    Rep(i, 1, n) chmax(k, b[i]);
    // Rep(i, 1, n) cout << b[i] << " \n"[i==n];
    co(n-k);

    return 0;
}
