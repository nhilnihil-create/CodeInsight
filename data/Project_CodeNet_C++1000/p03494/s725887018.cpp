#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k = 0;
    cin >> n;
    int a[n];
    cin >> a[0];
    int d = a[0];
    for (int i = 1; i < n; i++) 
    {
        cin >> a[i];
        d = __gcd(d, a[i]);
    }
    if (d % 2 != 0) cout << '0';
    else
    {
        while (d % 2 == 0)
        {
            d /= 2;
            k++;
        }
        cout << k;
    }
}