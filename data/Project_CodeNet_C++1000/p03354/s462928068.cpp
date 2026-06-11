#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

VVI g;
VI ids;

void dfs(int v, int p, int id){
    ids[v] = id;
    for(int d: g[v]){
        if (d == p) continue;
        if (ids[d] != -1) continue;
        dfs(d, v, id);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    VI p(n);
    rep(i,n){
        cin >> p[i];
        p[i]--;
    }

    g.resize(n);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    ids.resize(n, -1);
    int id = 0;
    rep(i,n){
        if (ids[i] != -1) continue;
        dfs(i, -1, id++);
    }

    int ans = 0;
    rep(i,n){
        if (ids[i] == ids[p[i]] || p[i] == i) ans++;
    }
    cout << ans << endl;
    return 0;
}