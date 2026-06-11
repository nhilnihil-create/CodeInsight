#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define repr(i, a, b) for(int i = b-1; i >= a; i--)
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
    Vl a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];

    ll s = 0, t = 0;
    rep(i, 0, n){
        if(a[i] < b[i]) s += (b[i] - a[i])/2; // bigger b
        if(a[i] > b[i]) t += a[i] - b[i]; // bigger a
    }
    if(s >= t) co("Yes");
    else co("No");

    return 0;
}


