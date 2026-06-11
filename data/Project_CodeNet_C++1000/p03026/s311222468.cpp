#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vll = vector<long long>;
using vp = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

int n;
vvi to;
vi cost;
vi ans;
int cnt;

void dfs(int v, int p=-1) {
    ans[v] = cost[cnt++];
    for (int nv : to[v]) {
        if (nv == p) continue;
        dfs(nv, v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    to.resize(n);
    rep(i, n-1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a].pb(b);
        to[b].pb(a);
    }
    cost.resize(n);
    rep(i, n) cin >> cost[i];
    sort(cost.rbegin(), cost.rend());

    ans.resize(n);
    dfs(0);
    cout << accumulate(cost.begin()+1, cost.end(), 0) << endl;
    rep(i, n) {
        if (i != 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;
}