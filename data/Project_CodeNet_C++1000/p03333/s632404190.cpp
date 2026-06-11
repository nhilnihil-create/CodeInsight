#include <bits/stdc++.h>

using namespace std;
long long mleft[100005];
long long mright[100005];

int main() {
    long long N;
    scanf("%lld", &N);
    for (int64_t i = 0; i < N; i++) {
        scanf("%lld %lld", &mleft[i], &mright[i]);
    }
    sort(mleft, mleft + N + 1, greater<long long>());
    sort(mright, mright + N + 1);
    long long sum = 0;
    for (long long i = 0; i <= N; i++) {
        if (mleft[i] > mright[i]) {
            sum += 2 * (mleft[i] - mright[i]);
        }
    }
    printf("%lld\n", sum);
    return 0;
}
