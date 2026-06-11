#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;
    double c;
    int d;
    cin >> a >> b;
    c = (a + b) / 2.0;
    d = int(c);
    if (c == d)
    {
        cout << d << endl;
    }
    else
    {
        cout << d + 1 << endl;
    }
}