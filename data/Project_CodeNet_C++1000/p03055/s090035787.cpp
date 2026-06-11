#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
template<class T> using vc = vector<T>;
template<class T> using vvc = vector<vector<T>>;

const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;
const ll INF = 1e16;
const ld EPS = 1e-11;
const ld PI = acos(-1.0L);
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define repr(i, n) for (ll i = (n)-1; i >= 0; i--)
#define repe(i, l, r) for (ll i = (l); i < (r); i++)
#define reper(i, l, r) for (ll i = (r)-1; i >= (l); i--)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

void init() {cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(15);}
//--------------------------------------------------------------------------------//
bool used1[200000], used2[200000];
ll dist1[200000], dist2[200000];
void dfs1(ll now, ll parent, ll depth, const vvc<ll>& G){
    dist1[now] = depth;
    for(auto to:G[now]){
        if (to == parent) continue;
        dfs1(to, now, depth + 1, G);
    }
}
void dfs2(ll now, ll parent, ll depth, const vvc<ll>&G){
    dist2[now] = depth;
    for(auto to:G[now]){
        if (to == parent) continue;
        dfs2(to, now, depth + 1, G);
    }
}
int main() {
    init();
    ll N;
    cin >> N;
    vvc<ll> G(N);
    rep(i,N-1){
        ll a,b;
        cin>>a>>b;
        a--, b--;
        G[a].eb(b);
        G[b].eb(a);
    }
    dfs1(0, -1, 1, G);
    ll max_u = max_element(dist1, dist1 + N) - dist1;

    dfs2(max_u, -1, 1, G);
    ll L = *max_element(dist2, dist2 + N);

    if(L==1){
        cout << "First" << endl;
    }
    else if(L==2){
        cout << "Second" << endl;
    }
    else if((L-2)%3==0){
        cout << "Second" << endl;
    }
    else{
        cout << "First" << endl;
    }
}