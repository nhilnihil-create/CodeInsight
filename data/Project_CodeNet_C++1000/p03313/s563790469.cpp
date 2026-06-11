#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> A(1 << N);
    for (int i = 0; i < 1 << N; i++) cin >> A[i];
    vector<int> first(1 << N), second(1 << N);
    for (int i = 0; i < 1 << N; i++) {
        for (int S = ~i & ((1 << N) - 1); S > 0; S = (S - 1) & ~i) {
            if (first[S | i] < A[i]) {
                second[S | i] = first[S | i];
                first[S | i] = A[i];
            } else if (second[S | i] < A[i]) {
                second[S | i] = A[i];
            }
        }
        if (first[i] < A[i]) {
            second[i] = first[i];
            first[i] = A[i];
        } else if (second[i] < A[i]) {
            second[i] = A[i];
        }
    }
    int ans = 0;
    for (int K = 1; K < 1 << N; K++) {
        ans = max(ans, first[K] + second[K]);
        cout << ans << '\n';
    }
}