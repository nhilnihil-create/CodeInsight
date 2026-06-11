#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, d[8], k = 0, s = 0;
    for (int i = 0; i < 8; i++) d[i] = 0;
    cin >> n;
    m = n;
    while (m != 0)
    {
        d[k] = m % 10;
        k++;
        m /= 10;
    }
    for (int i = 0; i < 8; i++) s += d[i];
    if (n % s == 0) cout << "Yes";
    else cout << "No";
}