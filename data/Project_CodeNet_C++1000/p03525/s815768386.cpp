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

ll d[13];

int main(){
    ll n; cin >> n;
    d[0]++;
    rep(i, 0, n){
        ll t; cin >> t;
        d[t]++;
        if(d[t] >= 3){
            co(0);
            return 0;
        }
    }
    set<ll> st;
    rep(i, 0, 13){
        if((i==0 || i==12) && d[i]==2){
            co(0);
            return 0;
        }
        if(d[i] == 2){
            d[i] == 0;
            st.insert(i);
            st.insert(24-i);
        }
    }
    int t = 0;
    rep(i, 0, 13){
        if(d[i]!=1) continue;
        if(t == 0){
            st.insert(i);
            t = 1;
        }else{
            st.insert(24-i);
            t = 0;
        }
    }
    Vl v;
    for(auto it : st) v.push_back(it);
    v.push_back(24);
    ll ans = 12;
    rep(i, 0, sz(v)-1) chmin(ans, v[i+1] - v[i]);
    co(ans);



    return 0;
}
