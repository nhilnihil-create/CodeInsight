#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1005;
const int Maxb = 40;

int n;
ll X[Maxn], Y[Maxn];
ll pw[Maxb];
ll my[Maxb];
int b = 32;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &X[i], &Y[i]);
        if (bool((X[i] + Y[i]) % 2) != bool((X[0] + Y[0]) % 2)) { printf("-1\n"); return 0; }
    }
    pw[0] = 1;
    for (int i = 1; i < b; i++)
        pw[i] = 2ll * pw[i - 1];
    for (int i = 0; i < b; i++)
        my[i] = pw[b - 1 - i];
    if ((X[0] + Y[0]) % 2 == 0)
        my[b++] = 1;
    printf("%d\n", b);
    for (int i = 0; i < b; i++)
        printf("%lld%c", my[i], i + 1 < b? ' ': '\n');
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < b; j++)
            if (abs(X[i]) >= abs(Y[i]))
                if (X[i] < 0) { printf("L"); X[i] += my[j]; }
                else { printf("R"); X[i] -= my[j]; }
            else if (Y[i] < 0) { printf("D"); Y[i] += my[j]; }
                 else { printf("U"); Y[i] -= my[j]; }
        printf("\n");
    }
    return 0;
}
