#include <bits/stdc++.h>
using namespace std;

#define      ll     long long int

int main()
{
    ll x, y, c = 0;
    cin >> x >> y;
    while (x <= y) {
        c++;
        x = x * 2;
    }
    cout << c << '\n';
    return 0;
}
