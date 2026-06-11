#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const long long INF = 1LL << 60;
const ll C = 1000000000+7;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> x(N);
    for(int i=0; i<N; i++) cin >> x[i];

    ll min_time = INF;
    for(int i=0; i<=N-K; i++) {
        ll t1 = abs(x[i]) + abs(x[i+K-1] - x[i]);
        ll t2 = abs(x[i + K - 1]) + abs(x[i+K-1] - x[i]);
        min_time = min(min_time, min(t1, t2));
    }
    cout << min_time << endl;
}