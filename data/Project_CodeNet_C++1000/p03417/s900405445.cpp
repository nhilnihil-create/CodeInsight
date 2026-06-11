#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n, m;
    cin >> n >> m;
    if (n * m == 1)
        cout << 1 << endl;
    else if (n == 1)
        cout << max(0ll, m - 2) << endl;
    else if (m == 1)
        cout << max(0ll, n - 2) << endl;
    else
        cout << max(0ll, n * m - 2 * m - 2 * n + 4) << endl;
}