#include<iostream>
#include<deque>
#include<vector>
using namespace std;

int main() {
    int K;
    cin >> K;

    vector<int> dist(K, 1e9+1); dist[1] = 1;
    deque<int> que; que.push_back(1);
    while(!que.empty()) {
        int now = que.front(); que.pop_front();
        int nxt1 = now + 1 >= K ? 0 : now + 1;
        if(dist[nxt1] > dist[now] + 1) {
            dist[nxt1] = dist[now] + 1;
            que.push_back(nxt1);
        }
        int nxt0 = now * 10 % K;
        if(dist[nxt0] > dist[now]) {
            dist[nxt0] = dist[now];
            que.push_front(nxt0);
        }
    }

    cout << dist[0] << endl;

    return 0;
}