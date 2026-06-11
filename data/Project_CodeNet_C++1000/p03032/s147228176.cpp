//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;


void solve() {
    int N, K; cin >> N >> K;
    vector<long long> V(N);
    for (int i = 0; i < N; i++) cin >> V[i];

    long long ans = 0;
    for (int p = 0; p <= min(K, N); p++) {
        for (int q = 0; p + q <= min(K, N); q++) {
            vector<long long> v;
            long long cur = 0;
            for (int i = 0; i < p; i++) v.push_back(V[i]), cur += V[i];
            for (int i = 0; i < q; i++) v.push_back(V[N-1-i]), cur += V[N-1-i];

            sort(v.begin(), v.end());
            for (int i = 0; i < min(K - p - q, (int)v.size()); i++) {
                if (v[i] < 0) cur -= v[i];
            }

            ans = max(ans, cur);
        }
    }

    cout << ans << endl;
}


int main() {
    solve();
    return 0;
}