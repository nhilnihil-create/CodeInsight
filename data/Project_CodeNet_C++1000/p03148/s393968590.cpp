#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i) 
#define rrep(i, a, b) for (int i = (a); i < (b); ++i)
#define PI acos(-1)
#define pcnt __builtin_popcountll
#define rng(a) a.begin(), a.end()
#define rrng(a) a.rbegin(), a.rend()
#define sz(x) (int)(x).size()
#define v(T) vector<T>
#define vv(T) v(v(T))
#define fi first
#define se second

using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using LP = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using tl = tuple<ll, ll, ll>;

template<typename T>inline istream& operator>>(istream&i,v(T)&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T1,typename T2>inline istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false; }

ll INF = 1001001001;
ll LINF = 1001001001001001001ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, k; cin>>n>>k;
    vector<LP> dt(n); cin>>dt;
    rep(i, n) swap(dt[i].fi, dt[i].se);
    sort(rrng(dt));

    vector<bool> used(n + 1);
    vl dub;
    ll kind = 0;
    ll deli = 0;
    rep(i, k) {
        if (used[dt[i].se]) dub.push_back(dt[i].fi);
        else kind++;
        used[dt[i].se] = true;
        deli += dt[i].fi;
    }
    ll cur = deli + kind * kind;
    ll ans = cur;
    rrep(i, k, n) {
        if (used[dt[i].se] || dub.empty()) continue;
        used[dt[i].se] = true;

        deli = deli - dub.back() + dt[i].fi;
        dub.pop_back();
        kind++;
        cur = deli + kind * kind;
        chmax(ans, cur);
    }
    cout<<ans<<endl;
}