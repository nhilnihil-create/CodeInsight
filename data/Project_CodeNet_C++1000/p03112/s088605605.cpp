#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define Rep(i,n) for(int i = 1; i <= n; i++)
#define sz(x) int(x.size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesorNo(a) printf(a ? "Yes\n" : "No\n")
#define endl '\n'
#define fi first
#define se second
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
template<class T> using V = vector<T>;
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,1,-1,-1,1};
const int inf = (1<<30)-1;
const ll infll = (1LL<<62)-1;
ll ceil(const ll &a, const ll &b){return ((a)+(b)-1)/b;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int main() {
    int a, b, q;
    cin >> a >> b >> q;
    V<ll> s(a), t(b);
    rep(i,a) cin >> s[i];
    rep(i,b) cin >> t[i];

    rep(i,q) {
        ll x;
        cin >> x;

        auto add = [&](V<ll> &c, V<ll> &C) {
            auto it = lower_bound(all(c),x);
            if(it != c.end()) C.push_back(*it);
            if(it != c.begin()) C.push_back(*(it-1));
        };

        V<ll> S(0), T(0);
        add(s,S);
        add(t,T);

        ll ans = infll;
        for(ll y:S)for(ll z:T) {
            ll d = max({x,y,z}) - min({x,y,z});
            if((y >= x) != (z >= x)) {
                d += min(abs(y-x), abs(z-x));
            }
            chmin(ans, d);
        }
        cout << ans << endl;
    } 
}