#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    rep(i, n) scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    int ans = a[a.size() - 1] - a[0];
    printf("%d\n", ans);
    return 0;
}