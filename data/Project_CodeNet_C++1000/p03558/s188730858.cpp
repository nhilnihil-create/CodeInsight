#include <bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin >> k;
    vector<int> used(k, 0);
    deque<pair<int, int>> dq; // 頂点, コスト
    dq.push_front(make_pair(1, 1)); // 1 -> 0 への最短距離
    while(!dq.empty()){
        auto cur = dq.front(); dq.pop_front();
        if(used[cur.first]) continue;
        used[cur.first] = 1;
        if(cur.first == 0){
            cout << cur.second << endl;
            return 0;
        }
        // 辺の重みが0なら先頭へ
        dq.push_front(make_pair((10 * cur.first) % k, cur.second));
        // 辺の重みが1なら後ろへ
        dq.push_back(make_pair((cur.first + 1) % k, cur.second + 1));
    }
}