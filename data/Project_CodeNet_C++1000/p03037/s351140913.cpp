#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int lmx = 1, rmn = n;
    for (int i = 1; i <= m; ++i){
        int l, r;
        scanf("%d %d", &l, &r);
        lmx = max(lmx, l);
        rmn = min(rmn, r);
    }
    int cnt = 0;
    if(rmn >= lmx) cnt = rmn - lmx + 1;
    printf("%d", cnt);
    return 0;
}