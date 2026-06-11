#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
    int n, x;
    scanf("%d %d", &n, &x);
    vector<int> m(n);
    rep(i, n) scanf("%d", &m[i]);
    sort(m.begin(), m.end());
    rep(i, n) x -= m[i];
    int count = m.size();
    while (x >= m[0])
    {
        x -= m[0];
        count++;
    }
    printf("%d\n", count);
    return 0;
}