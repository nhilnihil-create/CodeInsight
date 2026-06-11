#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1'000'000'007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)
#define repd(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=a-1; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define rALL(x) x.rbegin(), x.rend()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<vector<char>> g;
int main(){
    ll n;   cin >> n;
    vector<ll> a(n);
    rep(i, n)   cin >> a[i];
    vector<ll> gc(n), gcb(n);
    gc[0] = a[0];
    FOR(i, 1, n){
        gc[i] = gcd(gc[i-1], a[i]); 
    }
    gcb.back() = a.back();
    repd(i, n-1){
        gcb[i] = gcd(gcb[i+1], a[i]);
    }
    
    ll res=0;
    rep(i, n){
        ll fr=0, bc=0;
        if(0<i) fr = gc[i-1];
        if(i<n-1) bc = gcb[i+1];
        if(!fr || !bc) res = max(res, max(fr, bc));
        else res = max(res, gcd(fr, bc));
    }
    cout << res << endl;
}
