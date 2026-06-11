#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int> &S, int K) {
    deque<int> Q;
    Q.push_front(1);

    while(!Q.empty()) {
        int v = Q.front();
        Q.pop_front();
        
        int nv = v * 10 % K;
        if(S[nv] > S[v]) {
            S[nv] = S[v];
            Q.push_front(nv);
        }

        nv = (v + 1) % K;
        if(S[nv] > S[v] + 1) {
            S[nv] = S[v] + 1;
            Q.push_back(nv);
        }
    }
}

int main() {
    int K;
    cin >> K;

    vector<int> S(K, 100100101);
    S[1] = 1;

    bfs(S, K);
    cout << S[0] << endl;
}