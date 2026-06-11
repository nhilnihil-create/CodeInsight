#include <iostream>

using namespace std;

int n, m, k;

int main()
{
    cin >> m >> k;
    n = (1 << m) - 1;
    if (m == 1 && k == 0)
    {
        cout << "0 0 1 1";
        return 0;
    }
    if (k > n)
    {
        cout << -1;
        return 0;
    }
    int r = 0, t = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i != k) r ^= i;
    }
    if (r != k)
    {
        cout << -1;
        return 0;
    }
    cout << k << " ";
    for (int i = 0; i <= n; i++) if (i != k) cout << i << " ";
    cout << k << " ";
    for (int i = n; i >= 0; i--) if (i != k) cout << i << " ";
}
