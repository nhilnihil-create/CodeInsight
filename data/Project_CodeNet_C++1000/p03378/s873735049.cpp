#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);
    
    int a[m];
    rep(i, m) scanf("%d", &a[i]);

    int count_r = 0, count_l = 0;
    rep(i, m) {
        if(a[i] < x) ++count_l;
        else ++count_r;
    }
    printf("%d\n", min(count_r,count_l));
    return 0;
}