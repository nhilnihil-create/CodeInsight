#define _GLIBCXX_DEBUG
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<string>
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define rep2(i,s,n) for(int i=s;i< (int)n; i++)
#define ll long long 
#define all(v) v.begin(),v.end()
using namespace std;
using Graph = vector<vector<int>>;
// 深さ優先探索
vector<bool> seen;
void dfs(const Graph &G, int v) {
    seen[v] = true;
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue;
        dfs(G, next_v); // 再帰的に探索
    }
}

int main() {
    ll ans=0;
    // 頂点数と辺数
    int N, M; cin >> N >> M; 
    vector<pair<int,int>> P(M);
    // グラフ入力受取
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        P[i]={a-1,b-1};
    }
   rep(j,M){
     Graph G(N);
     rep(k,M){
       if(k!=j){
         G[P[k].first].push_back(P[k].second);
         G[P[k].second].push_back(P[k].first);
       }
     }
     //Graph G2(N)=G;
     //G[P[i].first].erase(G.begin()+P[i].second);
     //G[P[i].second].erase(G.begin()+P[i].first);
    // 全頂点が訪問済みになるまで探索
    int count = 0;
    seen.assign(N, false);
    for (int v = 0; v < N; ++v) {
        if (seen[v]) continue; // v が探索済みだったらスルー
        dfs(G, v); // v が未探索なら v を始点とした DFS を行う
        ++count;
    }
    if(count==2)ans++;
   }
  cout <<ans<<endl;
}

