#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    using P = pair<int, int>;
    vector<vector<P>> to(n);
    rep(i,n-1) {
        int u,v,w;
        cin >>u >> v >> w;
        u--;v--;
        to[u].emplace_back(v,w);
        to[v].emplace_back(u,w);
    }
    vector<bool> seen(n,false);
    vector<bool> w(n,false);
    w[0] = true;
    queue<int> q;
    q.emplace(0);
    while(!q.empty()) {
        int v = q.front();
        seen[v] = true;
        q.pop();
        for(auto next: to[v]) {
            int nv = next.first;
            int dist = next.second;
            if(seen[nv])continue;
            if(w[v] && dist%2 == 0 || !w[v] && dist%2 == 1) {
                w[nv] = true;
            } else {
                w[nv] = false;
            }
            q.emplace(nv);
        }
    }
    rep(i,n) {
        if(w[i]) cout << 0 << endl;
        else cout << 1 << endl;
    }
}
