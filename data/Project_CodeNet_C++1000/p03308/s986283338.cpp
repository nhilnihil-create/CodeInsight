#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

void solve(long long N, std::vector<long long> A) {
    ll ans = 0;
    for (ll i = 0; i < N; i++) {
        for (ll j = i + 1; j < N; j++) {
            ans = max(ans, abs(A[i] - A[j]));
        }
    }
    cout << ans << endl;
}

int main() {
    long long N;
    scanf("%lld", &N);
    std::vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }
    solve(N, std::move(A));
    return 0;
}
