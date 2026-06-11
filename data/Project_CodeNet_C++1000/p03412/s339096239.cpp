#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    int a[N];
    int b[N];
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);
    for (int i = 0; i < N; i++) scanf("%d", &b[i]);

    bool ans[29] = {};
    for (int i = 29; i >= 0; i--) {
        int x = 1 << (i + 1);
        for (int j = 0; j < N; j++) {
            a[j] %= x;
            b[j] %= x;
        }
        sort(b, b + N);

        for (int j = 0; j < N; j++) {
            int* pos1 = lower_bound(b, b + N, x / 2 - a[j]);
            int* pos2 = lower_bound(b, b + N, x / 2 * 2 - a[j]);
            int* pos3 = lower_bound(b, b + N, x / 2 * 3 - a[j]);
            int* pos4 = lower_bound(b, b + N, x / 2 * 4 - a[j]);
            int idx1 = distance(pos1, pos2);
            int idx2 = distance(pos3, pos4);
            ans[i] ^= (idx1 + idx2) % 2;
        }
    }

    int sum = 0;
    for (int i = 0; i < 29; i++) {
        sum += ans[i] << i;
    }
    printf("%d\n", sum);
    
    return 0;
}
