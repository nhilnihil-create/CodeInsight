#include <bits/stdc++.h>
template<class T> inline bool chmin(T&a, T b){if(a > b){a = b; return true;}else{return false;}}
template<class T> inline bool chmax(T&a, T b){if(a < b){a = b; return true;}else{return false;}}
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1.0)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

ll solve(ll x, ll a, ll b){
    ll ans = inf;
    chmin(ans, abs(x-a)+abs(a-b));
    chmin(ans, abs(x-b)+abs(a-b));
    return ans;
}

int main() {
    ll a, b, q;
    cin >> a >> b >> q;
    vector<ll> s(a), t(b);
    rep(i, a)cin >> s[i];
    rep(i, b)cin >> t[i];
    rep(i, q){
        ll x;
        cin >> x;
        auto it1 = lower_bound(all(s), x);
        auto it2 = lower_bound(all(t), x);
        ll a = inf, b = inf, c = inf, d = inf;
        if(it1 != s.begin())a = *(it1-1);
        if(it1 != s.end())b = *it1;
        if(it2 != t.begin())c = *(it2-1);
        if(it2 != t.end())d = *it2;
        ll ans = inf;
        chmin(ans, solve(x, a, c));
        chmin(ans, solve(x, a, d));
        chmin(ans, solve(x, b, c));
        chmin(ans, solve(x, b, d));
        cout << ans << endl;
    }
}
