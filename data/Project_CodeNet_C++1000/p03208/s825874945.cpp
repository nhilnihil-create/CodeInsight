#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 60;

int main() {
    int N, K; cin >> N >> K;
    vector<long long> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H.at(i);
    }
    sort(H.begin(), H.end());
    long long ans = INF;
    for (int i = 0; i < N-K+1; i++) {
        ans = min(ans, H.at(i+K-1) - H.at(i));
    }
    cout << ans << endl;
}