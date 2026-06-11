#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c, x, d = 0;
    cin >> a >> b >> c >> x;
    x /= 50;
    for (int i = 0; i <= min(a, x / 10); i++)
        for (int j = 0; j <= min(b, (x - i * 10) / 2); j++)
            if (x - 10 * i - j * 2 <= c) d++;
    cout << d;
}