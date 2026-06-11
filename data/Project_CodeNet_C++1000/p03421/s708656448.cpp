#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, A, B;
    scanf("%lld %lld %lld", &N, &A, &B);
    long long cnt = 0;
    if (N >= (A + B - 1) && N <= A * B) {
        while (1) {
            for (long long i = 1; i <= A; i++) {
                printf("%lld ", N - A + i);
            }
            cnt += 1;
            N -= A;
            if (B - cnt - 1 > N - A || N < 1) break;
        }
        if (N > 0){
            for (long long i = B - cnt; i <= N; i++) {
                printf("%lld ", i);
            }
            for (long long i = B - cnt - 1; i > 0; i--) {
                printf("%lld ", i);
            }
        }
    } else {
        printf("%d", -1);
    }

    return 0;
}
