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

using tl = tuple<ll, ll, ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll x, y, z, k;
    cin>>x>>y>>z>>k;
    vl as(x), bs(y), cs(z);
    cin>>as>>bs>>cs;

    sort(rng(as));
    reverse(rng(as));
    sort(rng(bs));
    reverse(rng(bs));
    sort(rng(cs));
    reverse(rng(cs));

    priority_queue<tl> q;
    q.emplace(as[0] + bs[0] + cs[0], 0, 0, 0);
    ll cnt = 0;
    vector<vector<vector<bool>>> used(x, vector<vector<bool>>(y, vector<bool>(z)));
    while(!q.empty() && cnt < k) {
        tl t = q.top(); q.pop();
        ll s = get<0>(t);
        ll a = get<1>(t);
        ll b = get<2>(t);
        ll c = get<3>(t);
        if (used[a][b][c]) continue;
        used[a][b][c] = true;
        cout<<s<<endl;
        if (a + 1 < x) q.emplace(as[a + 1] + bs[b] + cs[c], a + 1, b, c);
        if (b + 1 < y) q.emplace(as[a] + bs[b + 1] + cs[c], a, b + 1, c);
        if (c + 1 < z) q.emplace(as[a] + bs[b] + cs[c + 1], a, b, c + 1);
        cnt++;
    }
}