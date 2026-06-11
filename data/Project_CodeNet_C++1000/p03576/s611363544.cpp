#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i) 
#define PI acos(-1)
#define pcnt __builtin_popcountll
#define rng(a) a.begin(), a.end()
#define sz(x) (int)(x).size()
#define v(T) vector<T>
#define vv(T) v(v(T))
#define fi first
#define se second

using namespace std;
using ll = long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

template<typename T>inline istream& operator>>(istream&i,v(T)&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T1,typename T2>inline istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false; }

ll INF = 1001001001;
ll LINF = 5001001001001001001ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, k;
    cin>>n>>k;
    vector<LP> xy(n);
    cin>>xy;

    sort(rng(xy));
    ll l = 0, r = n - 1;
    ll ans = LINF;
    rep(l, n - k + 1) {
        for (int r = l + k - 1; r < n; ++r) {
            ll lx = xy[l].fi, rx = xy[r].fi;

            ll m = r - l + 1;
            vl ys;
            rep(i, m) ys.push_back(xy[l + i].se);
            sort(rng(ys));
            rep(b, m - k + 1) {
                for (int u = b + k - 1; u < m; ++u) {
                    ll ly = ys[b], ry = ys[u];
                    chmin(ans, (rx - lx) * (ry - ly));
                }
            }
        }
    }
    cout<<ans<<endl;
}