#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N, X;
    cin >> N >> X;
    vector<int> dist(N, 0);
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        dist[i] = abs(X - x);
    }

    int ans = dist[0];
    for (int i = 1; i < N; ++i) {
        ans = __gcd(ans, dist[i]);
    }

    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
