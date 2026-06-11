#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define debug(var) do{cout << #var << " : "; view(var);}while(0)
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
template<class T> void view(T e) {cout << e << endl;}
template<class T> void view(const vector<T> &v) {for(const auto &e : v){cout << e << " ";} cout << endl;}
template<class T> void view(const vector<vector<T>> &vv) {for(const auto &v : vv){view(v);}}
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;

int n;
vvint g;
priority_queue<int> q;
vint ans;

void bfs(int s) {
    queue<int> q_;
    q_.push(s);
    while (!q_.empty()) {
        int v = q_.front(); 
        q_.pop();
        ans[v] = q.top();
        q.pop();
        for (int n_v : g[v]) {
            if (ans[n_v] != -1) continue;
            q_.push(n_v);
        }
    }
}

int main() {
    cin >> n;
    g.resize(n);
    ans.assign(n,-1);
    rep(i,n-1) {
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    rep(i,n) {
        int x; cin >> x;
        q.push(x);
    }
    bfs(0);
    int sum = 0;
    rep(i,n) {
        if (i == 0) continue;
        sum += ans[i];
    }
    cout << sum << endl;
    rep(i,n) cout << ans[i] << " ";
}
