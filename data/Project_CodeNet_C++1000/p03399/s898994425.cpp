#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << min(a+c, min({a+d, b+c, b+d}));
}

