#include <bits/stdc++.h>
int main() {
    int N, M, X, Y; scanf("%d%d%d%d", &N, &M, &X, &Y);
    std::vector<int> x(N), y(M);
    for(int i=0; i<N; i++) scanf("%d", &x[i]);
    for(int i=0; i<M; i++) scanf("%d", &y[i]);

    int MX = *std::max_element(x.begin(), x.end());
    int MY = *std::min_element(y.begin(), y.end());
    for(int i=X+1; i<=Y; i++) {
        bool ok = true;
        ok &= MX < i;
        ok &= MY >= i;
        if(ok) {
            puts("No War");
            return 0;
        }
    }
    puts("War");
    return 0;
}
