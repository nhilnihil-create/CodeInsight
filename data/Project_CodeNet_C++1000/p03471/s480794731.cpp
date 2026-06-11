#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

void solve(long long N, long long Y) {
    rep(i, N + 1) {
        rep(j, N + 1) {
            if ((N - i - j) >= 0) {
                if ((i * 10000 + j * 5000 + (N - i - j) * 1000) == Y) {
                    cout << i << " " << j << " " << N - (i + j) << endl;
                    return;
                }
            }
        }
    }
    cout << "-1 -1 -1" << endl;
}

int main() {
    long long N;
    scanf("%lld", &N);
    long long Y;
    scanf("%lld", &Y);
    solve(N, Y);
    return 0;
}
