#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 200005;
const int MAXBIT = 29;

int n;
int A[MAXN], B[MAXN];
int AA[MAXN], BB[MAXN];

ll count(int L, int R) {
    ll res = 0;
    for (int i = n, l = 1, r = 1; i >= 1; i--) {
        while (r <= n && AA[i] + BB[r] < R)
            r++;
        while (l <= n && AA[i] + BB[l] < L)
            l++;
        res += r - l;
    }
    return res;
}

bool solve(int T) {
    sort(AA + 1, AA + n + 1);
    sort(BB + 1, BB + n + 1);
    return (count(T, T << 1) + count(3 * T, T << 2)) & 1;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", A + i);
    for (int i = 1; i <= n; i++)
        scanf("%d", B + i);

    int ans = 0;
    for (int b = 0, T; b < MAXBIT; b++) {
        T = 1 << b;
        for (int i = 1; i <= n; i++) {
            AA[i] = A[i] % (T << 1);
            BB[i] = B[i] % (T << 1);
        }
        ans += solve(T) << b;
    }
    printf("%d\n", ans);
    return 0;
}
