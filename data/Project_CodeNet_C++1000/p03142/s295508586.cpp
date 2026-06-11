//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    int n, m;
    cin >> n >> m;
    vvi G(n);
    vector<unordered_set<int> > G_(n);
    rep(i, n-1+m) {
        int a, b;
        cin >> a >> b;
        G[a-1].push_back(b-1);
        G_[b-1].insert(a-1);
    }

    int ne;
    rep(i, n) {
        if(G_[i].empty()) ne = i;
    }


    vi ans(n, -2);
    ans[ne] = -1;
    vi depth(n, -1);
    depth[ne] = 0;
    function<void(int)> dfs = [&](int i) {
        for(int nex:G[i]) {
            if(depth[nex] < depth[i]+1) {
                ans[nex] = i;
                depth[nex] = depth[i]+1;
            }
            if(G_[nex].size() != 1) G_[nex].erase(i);
            else dfs(nex);
        }
    };

    dfs(ne);

    rep(i, n) {
        cout << ans[i]+1 << '\n';
    }
}