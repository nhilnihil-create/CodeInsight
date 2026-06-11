#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, h, j = 0, k = 0;
    bool dead = false;
    cin >> n >> h;
    int a[n], b[n], c[n];
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    sort(a, a + n);
    sort(b, b + n);
    for (int i = 0; i < n; i++) c[i] = b[n - 1 - i];
    for (int i = 0; i < n; i++)
    {
        if (c[i] < a[n - 1]) break;
        j += c[i];
        k++;
        if (j >= h)
        {
            dead = true;
            cout << k;
            break;
        }
    }
    if (dead == false)
    {
        h -= j;
        if (h % a[n - 1] == 0) cout << k + h / a[n - 1];
        else cout << k + h / a[n - 1] + 1;
    }
}