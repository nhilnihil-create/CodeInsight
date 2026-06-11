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

    ll h, w;
    cin>>h>>w;
    vector<string> grid(h);
    cin>>grid;

    queue<tuple<ll, ll, ll>> q;
    vvl visited(h, vl(w, -1));
    rep(i, h) {
        rep(j, w) {
            if (grid[i][j] == '#') q.emplace(i, j, 0);
        }
    }
    ll ans = 0;
    while (!q.empty()) {
        auto v = q.front(); q.pop();
        ll x = get<0>(v), y = get<1>(v), d = get<2>(v);
        if (visited[x][y] != -1) continue;
        visited[x][y] = d;
        chmax(ans, d);
        if (x - 1 >= 0) q.emplace(x - 1, y, d + 1);
        if (x + 1 < h) q.emplace(x + 1, y, d + 1);
        if (y - 1 >= 0)  q.emplace(x, y - 1, d + 1);
        if (y + 1 < w) q.emplace(x, y + 1, d + 1);
    }
    cout<<ans<<endl;
}