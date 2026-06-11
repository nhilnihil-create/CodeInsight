#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx")

#include <cstdio>
#include <cstdlib>
using namespace std;

int N;
int A[200000];
int B[200000];

signed main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", A+i);
    for(int i = 0; i < N; ++i)
        scanf("%d", B+i);

    int ans = 0;

    int m = N/6 * 6;
    for(int i = 0; i < m; i += 6) {
        const int a0 = A[i];
        const int a1 = A[i+1];
        const int a2 = A[i+2];
        const int a3 = A[i+3];
        const int a4 = A[i+4];
        const int a5 = A[i+5];

        for(int j = 0; j < N; ++j) {
            ans ^= a0 + B[j];
            ans ^= a1 + B[j];
            ans ^= a2 + B[j];
            ans ^= a3 + B[j];
            ans ^= a4 + B[j];
            ans ^= a5 + B[j];
        }
    }

    for(int i = m; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            ans ^= A[i] + B[j];
        }
    }

    printf("%d\n", ans);

    fflush(stdout);
    _Exit(0);
}
