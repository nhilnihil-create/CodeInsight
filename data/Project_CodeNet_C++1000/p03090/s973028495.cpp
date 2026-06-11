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


int main(){
    Vp ans;
    ll n; cin >> n;
    Rep(i, 1, n-1) Rep(j, i+1, n){
        if(n%2 == 0){
            if(i+j != n+1) ans.push_back({i, j});
        }else{
            if(i+j != n) ans.push_back({i, j});
        }
    }
    co(sz(ans));
    for(auto it : ans) co(it.first << " " << it.second);

    return 0;
}
