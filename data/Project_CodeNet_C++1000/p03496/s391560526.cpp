#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, min, max, minpos = 1, maxpos = 1;
    cin >> n;
    cout << 2 * n - 1 << endl;
    int a[n];
    cin >> a[0];
    min = a[0];
    max = a[0];
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
        if (min > a[i])
        {
            min = a[i];
            minpos = i + 1;
        }
        if (max < a[i])
        {
            max = a[i];
            maxpos = i + 1;
        }
    }
    if (abs(max) >= abs(min))
    {
        for (int i = 1; i <= n; i++) cout << maxpos << ' ' << i << endl;
        for (int i = 1; i <= n - 1; i++) cout << i << ' ' << i + 1 << endl;
    }
    else
    {
        for (int i = 1; i <= n; i++) cout << minpos << ' ' << i << endl;
        for (int i = n; i > 1; i--) cout << i << ' ' << i - 1 << endl;
    }
}