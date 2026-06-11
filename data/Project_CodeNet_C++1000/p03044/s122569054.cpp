#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

using Edge = pair<long long, long long>;
using Graph = vector<vector<Edge> >;

vector<long long> ans;
long long N;
Graph G;

void dfs(long long v, long long p, long long c){
    ans[v] = c;//塗る

    for(auto nv : G[v]){
        if(nv.first == p) continue;

        if(nv.second % 2 != 0) dfs(nv.first, v, 1-c);//奇数なら違う色
        else dfs(nv.first, v, c);//偶数なら同じ色
    }
}

int main(){
    cin >> N;

    //assginでvectorを初期化 assgin(要素数, 値)
    // 初期化の際は値をもたずに型で指定できる vector<long long>()みたいに
    G.assign(N, vector<Edge>());

    for(long long i = 0; i < N-1; i++){
        long long u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }

    ans.assign(N, 0);

    dfs(0, -1, 0);

    for(auto v : ans){
        cout << v << endl;
    }
    return 0;
}