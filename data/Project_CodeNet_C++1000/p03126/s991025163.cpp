#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
//cout << setprecision(20) << 

int main() {
    ll N, M; cin >> N >> M;
    vector<int> v(M, 0);
    for (int i = 0; i < N; ++i) {
        ll K; cin >> K;
        for (int j = 0; j < K; ++j) {
            ll A; cin >> A;
            v[A-1]++;
        }
    }
    int count = 0;
    for (int i = 0; i < M; ++i) {
        if (v[i] == N) count++;
    }
    cout << count << endl;
}