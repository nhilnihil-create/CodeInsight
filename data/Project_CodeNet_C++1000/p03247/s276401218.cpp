#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

int main(){
    int N;
    cin >> N;
    ll x[N], y[N];
    rep(i, N){
        ll a, b;
        cin >> a >> b;
        x[i] = a+b, y[i] = a-b;
    }
    bool eve = false, odd = false;
    rep(i, N){
        if((x[i])%2 == 0) eve = true;
        else odd = true;
    }
    if(eve && odd) {cout << -1 << endl; return 0;}
    vector<ll> d;
    if(eve) d.pb(1);
    rep(i, 39) d.pb(1LL<<i);
    ll S = accumulate(all(d), 0LL);
    int m = sz(d);
    cout << m << endl;
    for(auto &e: d) cout << e << ' '; cout << endl;
    char mode[] = {'L', 'D', 'U', 'R'};
    rep(i, N){
        int ans[m];
        fill(ans, ans+m, 0);
        x[i] += S, y[i] += S;
        rep(j, m){
            ll e = d[j]<<1;
            if(x[i]&e) x[i] ^= e, ans[j] ^= 2;
            if(y[i]&e) y[i] ^= e, ans[j] ^= 1;
        }
        rep(j, m) cout << mode[ans[j]];
        cout << endl;
    }
}