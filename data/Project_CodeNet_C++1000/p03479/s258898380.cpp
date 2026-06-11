#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, n)               \
    for (int i = 0; i < n; i++) \
        ;
using namespace std;

int main()
{
    ll x, y;
    cin >> x >> y;
    int ans = 0;

    while (x <= y)
    {
        ans++;
        x += x;
    }
    cout << ans << endl;
    return 0;
}