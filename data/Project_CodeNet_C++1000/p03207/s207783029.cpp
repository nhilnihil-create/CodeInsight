#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
    int n;
    scanf("%d", &n);
    vector<int> p(n);
    rep(i, n) scanf("%d", &p[i]);
    sort(p.begin(), p.end());
    reverse(p.begin(), p.end());
    p[0] /= 2;
    int ans = 0;
    rep(i, n) ans += p[i];
    printf("%d\n", ans);
    return 0;
}