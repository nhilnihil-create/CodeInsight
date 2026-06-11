#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int q;
    cin >> q;
    while(q--)
    {
        ll a, b;
        cin >> a >> b;
        ll l = min(a, b);
        ll h = max(a, b);
        if(l == 1 && h == 1)
        {
            cout << 0 << endl;
            continue;
        }
        else if(l == 1 && h == 2)
        {
            cout << 0 << endl;
            continue;
        }
        if(a == b)
        {
            cout << 2 * (a-1) << endl;
            continue;
        }

        ll x = sqrt(a*b) / 1;
        if(x * (x+1) < a * b)
        {
            cout << 2 * x - 1 << endl;
        }
        else
        {
            if(x * x == a * b) cout << 2 * x - 3 << endl;
            else cout << 2 * x - 2 << endl;
        }
    }
}
