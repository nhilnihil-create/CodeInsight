#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a, b;
    cin >> a >> b;
    int d = b - a;
    d = (d + 1) * d / 2;
    cout << d - b;
}
