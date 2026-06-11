#include <bits/stdc++.h>

void print(int d) { printf("%d\n", d); }

int main(){
    int m, k;
    scanf("%d%d", &m, &k);
    int n = std::pow(2, m);
    
    if (n <= k || (m == 1 && k == 1)) { print(-1); return 0; }
    if (m == 1 && k == 0) { printf("1 0 0 1\n"); return 0; }
    for (int d = 0; d < n; d++) if (d != k) { print(d); } print(k);
    for (int d = n-1; d >= 0; d--) if (d != k) { print(d); } print(k);
    return 0;
}
