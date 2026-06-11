#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi=vector<int>;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }

int main() {
    int N;
    cin >> N;

    vector<pair<int,ll>> G[N];
    for (int i=0; i<N-1; ++i)  {
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        G[a].push_back({b,c%2});
        G[b].push_back({a,c%2});
    }
    vector<int> dist(N,-1);
    queue<int> que;

    dist[0]=0;
    que.push(0);

    while(!que.empty()){
        int v = que.front();
        que.pop();
        for(auto nv : G[v]) {
            if(dist[nv.first]!=-1) continue;
            if(!nv.second) dist[nv.first]=dist[v];
            else dist[nv.first]=!dist[v];
            que.push(nv.first);
        }
    }
    for(int v=0; v<N; ++v) cout << dist[v] << "\n";
    return 0;
}