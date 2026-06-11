#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> X(M);
    for (int i = 0; i < M; i++) cin >> X[i];
    sort(X.begin(), X.end());

    vector<int> dist(M-1);
    for (int i = 0; i < M-1; i++) dist[i] = X[i+1] - X[i];
    sort(dist.begin(), dist.end());

    long long ret = X[M-1] - X[0];

    for (int i = 0; i < N-1; i++) {
        if (M-2-i < 0) break;
        ret -= dist[M-2-i];
    }

    cout << ret << endl;
    return 0;
}