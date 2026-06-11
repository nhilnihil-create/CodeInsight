#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n, m;
    cin >> n >> m;
    vector<set<ll>> shown(n);
    vector< vector<ll> > G(n);
    rep(i, 0, n+m-1) {
        ll from, to;
        cin >> from >> to;
        from--; to--;
        G[from].push_back(to);
        shown[to].insert(from);
    }
    ll rt;
    rep(i, 0, n) if(shown[i].empty()) rt = i;
    vector<ll> rank(n, -1), access(n, 0), parent(n, -1);
    rank[rt] = 0;
    parent[rt] = -1;
    queue<ll> que;
    que.push(rt);
    while(!que.empty()){
        auto q = que.front();
        // cerr << q << endl;
        que.pop();
        for(auto g : G[q]) {
            access[g]++;
            if(access[g] < shown[g].size()) continue;
            ll mx = -100, prt = -1;
            for(auto e : shown[g]) {
                if(mx < rank[e]) {
                    mx = rank[e];
                    prt = e;
                }
            }
            parent[g] = prt;
            rank[g] = mx+1;
            que.push(g);
        }
    }
    rep(i, 0, n) cout << parent[i]+1 << endl;
    return 0;
}