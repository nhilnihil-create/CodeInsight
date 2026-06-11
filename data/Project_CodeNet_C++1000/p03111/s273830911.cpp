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
ll LINF = 1001001001001001001ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, a, b, c;
    cin>>n>>a>>b>>c;
    vl ls(n);
    cin>>ls;

    ll ans = LINF;
    rep(i, 1<<(2 * n)) {
        ll res = 0;
        ll temp = i;
        vl g(4);
        rep(j, n) {
            if (temp % 4 != 3 && g[temp % 4] != 0) res += 10;
            g[temp % 4] += ls[j];
            temp /= 4;
        }
        if (g[0] == 0 || g[1] == 0 || g[2] == 0) continue;
        res += abs(g[0] - a) + abs(g[1] - b) + abs(g[2] - c);
        chmin(ans, res);
    }

    cout<<ans<<endl;
}