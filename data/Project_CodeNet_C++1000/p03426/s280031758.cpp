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

    ll h, w, d;
    cin>>h>>w>>d;
    vvl grid(h, vl(w));
    cin>>grid;
    vector<LP> as(h * w);
    rep(i, h) rep(j, w) {
        as[grid[i][j] - 1] = LP(i, j);
    }

    vvl ss(d, vl(h * w / d + 10));
    rep(i, d) {
        ll cur = i;
        ll j = 0;
        while (cur + d < h * w) {
            ss[i][j + 1] = ss[i][j] + abs(as[cur + d].fi - as[cur].fi) + abs(as[cur + d].se - as[cur].se);
            j++;
            cur += d;
        }
    }
    ll Q;
    cin>>Q;
    rep(q, Q) {
        ll l, r;
        cin>>l>>r; l--; r--;
        ll m = l % d;
        cout<<ss[m][r / d] - ss[m][l / d]<<endl;
    }
}