#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 100100100;

int main()
{
    ll s;
    cin >> s;

    int x;
    int ans = INF;
    while (s > 100)
    {
        x = s % 1000;
        ans = min(abs(753 - x), ans);
        s /= 10;
    }

    cout << ans << endl;
    return 0;
}