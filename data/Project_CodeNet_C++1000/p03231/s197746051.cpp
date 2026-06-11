#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    ll N, M; cin >> N >> M;
    ll L = lcm(N,M);
    string S,T; cin >> S >> T;
    if (N < M) {
        swap(N,M);
        swap(S,T);
    }
    if (N % M == 0) {
        cout << -1 << endl;
        return 0;
    }
    ll C = lcm(L/N, L/M);
    for (int i = 0; i * C * M / L <= M; i++) {
        if (S[i*C*N/L] != T[i*C*M/L]) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << L << endl;
}
