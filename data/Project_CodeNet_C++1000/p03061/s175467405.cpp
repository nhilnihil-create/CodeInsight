#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define ld long double
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
// const ll INF = 1LL << 30;
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

ll l[100050], r[100050];

ll gcd(ll a, ll b){
    if(a == 0 || b == 0){
        return max(a, b);
    }
    while(1){
        if(a < b) swap(a, b);
        if(!b) break;
        a %= b;
    }
    return a;
}

int main() {
    ll n; cin >> n;
    Vl a(n+1);
    Rep(i, 1, n) cin >> a[i];
    Rep(i, 1, n){
        l[i] = gcd(a[i], l[i-1]);
    }
    for(int i = n; i >= 1; i--){
        r[i] = gcd(a[i], r[i+1]);
    }
    ll ans = -1;
    Rep(i, 1, n){
        chmax(ans, gcd(l[i-1], r[i+1]));
    }
    co(ans);

    return 0;
}

