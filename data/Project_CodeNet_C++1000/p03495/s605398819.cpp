#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k, d = 0, s = 0;
    cin >> n >> k;
    int a[n], p[n];
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
        p[i] = 0;
    }
    p[0] = 1;
    sort(a, a + n);
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[i - 1]) 
        {
            d++;
            p[d] = 1;
        }
        else p[d]++;
    }
    d++;
    if (d <= k) cout << '0';
    else
    {
        d -= k;
        sort(p, p + n);
        k = 0;
        for (int i = 0; i < n; i++)
        {
            if (p[i] > 0)
            {
                s += p[i];
                k++;
            }
            if (k == d) break;
        }
        cout << s;
    }
}