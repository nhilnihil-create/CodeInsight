#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
using namespace std;
int mod = 1000000007;

int par[100001];
vector<int> nodes[100001];
vector<int> come[100001];
bool visited[100001] = {};

void init(){
    rep(i, 100001) par[i] = 0;
}

void toposort(int s, vector<int> &order){
    visited[s] = true;
    for(auto to: nodes[s]){
        if(visited[to]) continue; //探索済み -> スキップ
        toposort(to, order);
    }
    //再帰を抜け出すときにorderに追加
    order.push_back(s);
}

int main(void){
    vector<int> order;
    int N, M; cin >> N >> M;
    rep(i, N-1+M){
        int a, b; cin >> a >> b;
        nodes[a].push_back(b);
        come[b].push_back(a);
    }
    for(int i = 1; i <= N; i++){
        if(!visited[i]) toposort(i, order);
    }
    reverse(order.begin(), order.end());
    rep(i, order.size()){
        for(auto to: nodes[order[i]]){
            par[to] = order[i];
        }
    }
    for(int i = 1; i <= N; i++) cout << par[i] << endl;
    return 0;
}