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

ll n, m;
vvl to, ot;

ll dfs(ll v) {
    if (ot[v].size() == 0) return v;
    return dfs(ot[v][0]);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n>>m;
    to = vvl(n);
    ot = vvl(n);
    rep(i, n + m - 1) {
        ll v1, v2;
        cin>>v1>>v2; v1--; v2--;

        to[v1].push_back(v2);
        ot[v2].push_back(v1);
    }

    ll r = dfs(0);
    vl ps(n);
    ps[r] = -1;
    vl in(n);
    rep(i, n) in[i] = ot[i].size();
    queue<ll> q;
    q.push(r);
    while(!q.empty()) {
        ll v = q.front(); q.pop();

        for (auto nv : to[v]) {
            in[nv]--;
            if (in[nv] == 0) {
                ps[nv] = v;
                q.push(nv);
            }
        }
    }
    rep(i, n) cout<<ps[i] + 1<<endl;
}