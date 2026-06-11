#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    int P[N];
    for(int i = 0; i < N; i++) cin >> P[i];
    int length[N + 1];
    for(int i = 0; i <= N; i++) length[i] = -1;
    int maximum = 1;
    for(int i = 0; i < N; i++) {
        length[P[i]] = max(1, length[P[i] - 1] + 1);
        maximum = max(maximum, length[P[i]]);
    }
    cout << N - maximum << "\n";
    return 0;
}
