#include <bits/stdc++.h>
using namespace std;


int main() {
    int N, M;
    cin >> N >> M;
    vector<int> v(M);
    for (int i = 0; i < M; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector<int> dist(M-1);
    for (int i = 0; i < M - 1; i++) {
        dist[i] = v[i+1] - v[i];
    }
    sort(dist.begin(), dist.end());
    long long ans = 0;
    for (int i = 0; i < M - N; i++) {
        ans += dist[i];
    }
    cout << ans << endl;
}