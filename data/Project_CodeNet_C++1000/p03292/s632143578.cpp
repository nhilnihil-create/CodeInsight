#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

void solve(std::vector<long long> A) {
    ll a = abs(A[0] - A[1]);
    ll b = abs(A[1] - A[2]);
    ll c = abs(A[2] - A[0]);
    cout << a + b + c - max(max(a, b), c) << endl;
}

int main() {
    std::vector<long long> A(3);
    for (int i = 0; i < 3; i++) {
        scanf("%lld", &A[i]);
    }
    solve(std::move(A));
    return 0;
}
