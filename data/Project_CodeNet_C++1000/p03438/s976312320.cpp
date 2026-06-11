#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N), B(N);

    ll C = 0, X = 0, Y = 0;
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];
    for (int i = 0; i < N; ++i) C += B[i] - A[i];
    for (int i = 0; i < N; ++i) {
        if (A[i] > B[i]) X += A[i] - B[i];
        else Y += (B[i] - A[i] + 1) / 2;
    }
    puts(max(X, Y) <= C ? "Yes" : "No");
}
