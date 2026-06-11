#include <bits/stdc++.h>
int main() {
    std::vector<int> V(3);
    for(int i=0; i<3; i++) scanf("%d", &V[i]);
    std::sort(V.rbegin(), V.rend());
    int ans = V[0] * 10 + V[1] + V[2];
    printf("%d\n", ans);
}
