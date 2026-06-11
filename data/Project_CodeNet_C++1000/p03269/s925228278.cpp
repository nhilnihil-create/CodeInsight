#include <bits/stdc++.h>

using namespace std;

int main()
{
    int l;
    cin >> l;
    int n = 32 - __builtin_clz(l);
    int m = (n - 1) * 2 + __builtin_popcount(l) - 1;
    cout << n << " " << m << endl;
    for (int i = 1; i < n; i++)
    {
        if (l % 2 == 1)
        {
            l--;
            cout << i << " " << n << " " << l << endl;
        }
        cout << i << " " << i + 1 << " " << l / 2 << endl;
        cout << i << " " << i + 1 << " " << 0 << endl;
        l /= 2;
    }
    return 0;
}
