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
#define fi first
#define se second

////////////////////////////////////////////////////////

int main() {
    ll n; cin >> n;
    Vl a(n); 
    bool f = false;
    ll m = INF;
    rep(i, 0, n){ 
        cin >> a[i]; 
        if(a[i]==0) f = true;
        chmin(m, abs(a[i]));
    }
    ll cnt = 0;
    rep(i, 0, n){
        if(a[i]<0) cnt++;
    }
    if(f){
        ll ans = 0;
        rep(i, 0, n) ans += abs(a[i]);
        co(ans);
    }else{
        ll ans = 0;
        rep(i, 0, n) ans += abs(a[i]);
        if(cnt%2==0){
        }else{
            ans -= 2*m;
        }
        co(ans);
    }

    
    return 0;
}
