#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_N = 5e3 + 10;

int N, P[MAX_N], pre2d[MAX_N][MAX_N];
ll A, B, F[MAX_N];

int count(int x1, int x2, int y1, int y2) {
    return pre2d[x2][y2] - pre2d[x2][y1 - 1] - pre2d[x1 - 1][y2] + pre2d[x1 - 1][y1 - 1];
}

int main() {
    scanf("%d%lld%lld", &N, &A, &B);
    for (int i = 1; i <= N; i++) scanf("%d", &P[i]);
    P[0] = 0; P[N + 1] = N + 1;
    for (int i = 1; i <= N; i++) {
        pre2d[i][P[i]] = 1;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) pre2d[i][j] += pre2d[i][j - 1];
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) pre2d[i][j] += pre2d[i - 1][j];
    }
    for (int i = 1; i <= N + 1; i++) {
        F[i] = LLONG_MAX;
        for (int j = 0; j < i; j++) {
            if (P[j] > P[i]) continue;
            ll v = F[j];
            int tot = i - j - 1, heavy;
            if (A >= B) {
                heavy = count(j + 1, i - 1, P[i], N);
            } else {
                heavy = count(j + 1, i - 1, 1, P[j]);
            }
            v += max(A, B) * heavy + min(A, B) * (tot - heavy);
            F[i] = min(F[i], v);
        }
    }
    printf("%lld\n", F[N + 1]);
}
