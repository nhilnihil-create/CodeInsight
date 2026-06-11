#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

void solve(long long N) {
    if (N % 2 == 0) {
        cout << N << endl;
    } else {
        cout << 2 * N << endl;
    }
}

int main() {
    long long N;
    scanf("%lld", &N);
    solve(N);
    return 0;
}
