#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q, l, r, i;
    string s;
    cin >> n >> q;
    cin >> s;
    int a[n + 1] = {};

    for (i = 0; i < n; i++)
    {
        if (i != 0 && s[i - 1] == 'A' && s[i] == 'C')
            a[i] = a[i - 1] + 1;
        else if (i == 0)
            a[i] = a[i];
        else
            a[i] = a[i - 1];
    }
    while (q--)
    {
        cin >> l >> r;
        l--, r--;
        if (l == 0)
            cout << a[r] << endl;
        else
            cout << a[r] - a[l] << endl;
    }
}