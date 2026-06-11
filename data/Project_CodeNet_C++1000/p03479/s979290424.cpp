#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll x, y;
    int res = 0;
    cin >> x >> y;

    ll i = x;
    while(i <= y)
    {
        i = i * 2;
        res++;
    }

    cout << res << "\n";
}
