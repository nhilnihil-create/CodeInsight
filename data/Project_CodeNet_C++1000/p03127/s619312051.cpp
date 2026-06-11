#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y) { return (x % y) ? gcd(y, x % y) : y; }

int main()
{
    int n, a, b;
    cin >> n;
    cin >> a;
    for (int i = 1; i < n; i++)
    {
        cin >> b;
        a = gcd(a, b);
    }
    cout << a << endl;

    return 0;
}