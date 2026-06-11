#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 500 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int d[5];

int main() {
    for(int i = 0; i < 3; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        ++d[u];
        ++d[v];
    }
    int odd = 0;
    for(int i = 1; i <= 4; ++i) {
        if(d[i]&1) ++odd;
    }
    if(odd == 2) puts("YES");
    else puts("NO");
    return 0;
}
