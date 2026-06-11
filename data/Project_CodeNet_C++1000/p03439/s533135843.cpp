#include <bits/stdc++.h>
using namespace std;

int f(int x) {
    printf("%d\n", x); fflush(stdout);
    char buf[255];
    scanf("%s", buf);
    if (buf[0] == 'V') exit(0);
    return buf[0] == 'M';
}
int main() {
    int N; scanf("%d", &N);
    int L = 0, Lt = f(L);
    int R = N - 1, Rt = f(R);
    while (1) {
        int M = (L + R) / 2;
        int v = f(M);
        if (abs(L - M) % 2 != abs(Lt - v) % 2) {
            R = M;
            Rt = v;
        }
        else {
            L = M;
            Lt = v;
        }
    }
}