#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int k;
    cin >> k;
    vector<ll> a(k);
    for(int i = 0; i < k; i++)
    {
        cin >> a[i];
    }
    if(a[k-1] != 2)
    {
        cout << -1 << endl;
        return 0;
    }

    ll l = 2, h = 3;
    for(int i = k-2; i >= 0; i--)
    {
        if(a[i] > h)
        {
            cout << -1 << endl;
            return 0;
        }
        if(a[i] >= l) l = a[i];
        else
        {
            l = ((l-1)/a[i] + 1) * a[i];
        }
        ll x = h / a[i] * a[i];
        h = x + a[i] - 1;
        if(l > h)
        {
          cout << -1 << endl;
          return 0;
        }
    }
    cout << l << " " << h << endl;
}
