#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
    int n, t;
    scanf("%d%d", &n, &t);
    vector<pair<int, int>> vec(n);
    rep(i, n) {
        int a, b;
        scanf("%d%d", &a, &b);
        vec.at(i) = make_pair(a, b);
    }
    sort(vec.begin(), vec.end());
    rep(i, n) {
        if(vec[i].second <= t) {
            int ans = vec[i].first;
            printf("%d\n", ans);
            return 0;
        }
    }
    printf("TLE\n");
    return 0;
}