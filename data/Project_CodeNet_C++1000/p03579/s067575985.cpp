#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i) 
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

    ll n, m;
    cin>>n>>m;
    vvl to(n);
    rep(i, m) {
        ll v1, v2;
        cin>>v1>>v2; v1--; v2--;

        to[v1].push_back(v2);
        to[v2].push_back(v1);
    }

    queue<LP> q;
    q.emplace(0, 0);
    vvl visited(n, vl(2));
    while (!q.empty()) {
        LP p = q.front(); q.pop();
        ll v = p.fi;
        ll d = p.se;
        if (visited[v][d]) continue;

        visited[v][d] = true;
        for (auto nv : to[v]) {
            q.emplace(nv, (d + 1) % 2);
        }
    }
    ll oc = 0, ec = 0, dc = 0;
    rep(i, n) {
        if (visited[i][0]) ec++;
        if (visited[i][1]) oc++;
        if (visited[i][0] && visited[i][1]) dc++;
    }
    cout<<ec * oc - dc * (dc - 1) / 2 - m - dc<<endl;
}