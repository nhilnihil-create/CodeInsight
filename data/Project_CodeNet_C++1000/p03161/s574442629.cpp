#include <bits/stdc++.h>
using namespace std;


int main() {
    int N, K;
    cin >> N >> K;
    vector<int> h(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> h[i];
    }

    vector<int> cost(N + 1, 0);
    for (int i = 2; i <= N; i++) {
        int minimum = INT_MAX;
        for(int j = 1; j <= K; j++) {
            if (i - j <= 0) continue;
            minimum = min(minimum, cost[i - j] + abs(h[i]- h[i-j]));            
        }
        cost[i] = minimum;
    }

    cout << cost[N] << endl;
}