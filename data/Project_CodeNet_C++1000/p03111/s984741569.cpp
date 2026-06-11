#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define repr(i, a, b) for(int i = a; i >= b; i--)
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

void print(Vl vec){
    rep(i, 0, sz(vec)){
        if(i) cout << " ";
        cout << vec[i];
    }
    coel;
}

////////////////////////////////////////////////////////
ll n, a, b, c; 
ll ans = INF;
Vl l;
ll sum = 0;

void saiki(ll x, ll y, ll z, ll w, ll cost){
    if(w == n){
        if(x==0 || y==0 || z==0) return;
        cost += abs(a-x)+abs(b-y)+abs(c-z);
        chmin(ans, cost);
    }else{
        saiki(x+l[w], y, z, w+1, x ? cost+10 : cost);
        saiki(x, y+l[w], z, w+1, y ? cost+10 : cost);
        saiki(x, y, z+l[w], w+1, z ? cost+10 : cost);
        saiki(x, y, z, w+1, cost);
    }
}

int main() {
    cin >> n >> a >> b >> c;
    l.resize(n);
    rep(i, 0, n) cin >> l[i];
    rep(i, 0, n) sum += l[i];

    saiki(0, 0, 0, 0, 0);
    co(ans);

    return 0;
}
