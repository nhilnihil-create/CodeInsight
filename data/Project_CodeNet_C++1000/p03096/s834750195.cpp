#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int N, nint;
    scanf("%d", &N);
    int prv[200000], locc[N], dptable[N];
    fill_n(prv, 200000, -1);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &nint);
        locc[i] = prv[nint - 1];
        prv[nint - 1] = i;
    }
    dptable[0] = 1;
    for (int i = 1; i < N; ++i) {
        dptable[i] = dptable[i - 1];
        if (locc[i] != i - 1 && locc[i] != -1) dptable[i] = (dptable[i] + dptable[locc[i]]) % 1000000007;
    }
    printf("%d", dptable[N - 1]);
    return 0;
}