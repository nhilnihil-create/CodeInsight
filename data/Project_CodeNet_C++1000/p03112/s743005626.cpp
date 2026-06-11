#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i) 
#define PI acos(-1)
#define pcnt __builtin_popcountll
#define rng(a) a.begin(), a.end()
#define sz(x) (int)(x).size()
#define v(T) vector<T>
#define vv(T) v(v(T))

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

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

    ll a, b, q;
    cin>>a>>b>>q;
    vl ss(a), ts(b), xs(q);
    cin>>ss>>ts>>xs;

    for (auto x : xs) {
        auto sit = lower_bound(rng(ss), x);
        ll sl = *(sit - 1), su = *sit;
        auto tit = lower_bound(rng(ts), x);
        ll tl = *(tit - 1), tu = *tit;
        ll ans = LINF;
        if (sit != ss.begin() && tit != ts.begin()) chmin(ans, max(x - sl, x - tl));
        if (sit != ss.end() && tit != ts.end()) chmin(ans, max(su - x, tu - x));
        if (sit != ss.begin() && tit != ts.end()) chmin(ans, 2 * (x - sl) + tu - x);
        if (sit != ss.end() && tit != ts.begin()) chmin(ans, 2 * (x - tl) + su - x);
        if (sit != ss.end() && tit != ts.begin()) chmin(ans, 2 * (su - x) + x - tl);
        if (sit != ss.begin() && tit != ts.end()) chmin(ans, 2 * (tu - x) + x - sl);
        cout<<ans<<endl;
    }
}