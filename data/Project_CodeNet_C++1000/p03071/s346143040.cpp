//  ©   ___MRX___

#include <bits/stdc++.h>
    using namespace std;

#define ll long long int

int main()
{
    int a, b, x = 0, i = 0;
    cin >> a >> b;
    while(i < 2) {
        x += max(a, b);
        a > b ? --a : --b;
        i++;
    }

    cout << x << '\n';

    return 0;
}
