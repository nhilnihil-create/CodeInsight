#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
using pll = pair<long long, long long>;

int main() {
    int N, M; cin >> N >> M;
    vector<long long> A(N), B(M), C(M);
    for (int i = 0; i < N; ++i) cin >> A[i];
    sort(A.begin(), A.end());
    B.resize(M);
    C.resize(M);
    for (int i = 0; i < M; ++i) cin >> B[i] >> C[i];

    // C をソート (B をまとめて)
    vector<int> id(M);
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&](int i, int j) {
            return C[i] > C[j];});

    // A (小さい順) と C (大きい順) とを比べて大きい方を足していく
    long long sum = 0;
    long long K = 0;
    for (auto i : id) {
        for (int j = 0; j < B[i]; ++j) {
            if (K >= N) break;
            sum += max(A[K++], C[i]);  
        }
    }
    for (int i = K; i < N; ++i) sum += A[i];        
    cout << sum << endl;
}