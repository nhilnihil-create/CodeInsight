#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
    vector<int> vec(3);
    rep(i, 3) scanf("%d", &vec[i]);
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    int ans = vec[0] * 10 + vec[1] + vec[2];
    printf("%d\n", ans);
    return 0;
}