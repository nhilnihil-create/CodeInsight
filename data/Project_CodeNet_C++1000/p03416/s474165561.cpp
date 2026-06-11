# include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, n = 0, c, d, e, f;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        c = i / 10000;
        d = i % 10;
        e = (i / 10) % 10;
        f = (i / 1000) % 10;
        if (c == d && e == f) n++;
    }
    cout << n;
}