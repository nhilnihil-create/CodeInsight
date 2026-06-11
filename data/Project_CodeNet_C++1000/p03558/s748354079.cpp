#include <bits/stdc++.h>
using namespace std;

void dijkstra(vector<int> &S, int K) {
    using P = pair<int, int>;

    priority_queue<P, vector<P>, greater<P>> que;
    que.emplace(S[1], 1);

    while(!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if(S[v] < p.first) continue;

        for(int y=0; y<10; ++y) {
            int nv = (10 * v + y) % K;
            if(S[nv] > S[v] + y) {
                S[nv] = S[v] + y;
                que.emplace(S[nv], nv);
            }
        }
    }
}

int main() {
    int K;
    cin >> K;

    vector<int> S(K, 100100101);
    for(int i=1; i<min(10, K); ++i) S[i] = i;

    dijkstra(S, K);
    cout << S[0] << endl;
}