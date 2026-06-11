#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;
using ll = long long;
int mod = 1000000007;

vector<int> nodes[100001];

void toposort(int s, vector<int> &order, vector<bool> &seen){
    seen[s] = true;
    for(auto to: nodes[s]){
        if(seen[to]) continue; //探索済み -> スキップ
        toposort(to, order, seen);
    }
    //再帰を抜け出すときにorderに追加
    order.push_back(s);
}

int main(void){
    int N, M; cin >> N >> M;
    int loop = N-1+M;
    int cnt[N+1] = {0};
    vector<int> come[N+1];
    cnt[0] = -1;
    rep(i, loop){
        int from, to; cin >> from >> to;
        nodes[from].push_back(to);
        come[to].push_back(from);
        cnt[to]++;
    }
    vector<bool> seen(N+1, 0);
    vector<int> order;
    for(int i = 1; i <= N; i++){
        if(seen[i]) continue;
        toposort(i, order, seen);
    }

    reverse(order.begin(), order.end());
    
    vector<int> pos_in_order(N+1);
    rep(i, order.size()){
        pos_in_order[order[i]] = i;
    }

    for(int i = 1; i <= N; i++){
        if(come[i].size() == 0) cout << 0 << endl;
        else{
            int par_pos = -1;
            rep(j, come[i].size()) par_pos = max(par_pos, pos_in_order[come[i][j]]);
            cout << order[par_pos] << endl;
        }
    }
    
    return 0;
}