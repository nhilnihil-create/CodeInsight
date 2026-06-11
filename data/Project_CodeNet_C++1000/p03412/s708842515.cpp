#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    ll ans = 0;
    for(int i = 28; i >= 0; i--)
    {
        ll tmp = 1 << i;
        for(int j = 0; j < n; j++)
        {
            b[j] &= tmp*2 - 1;
        }
        sort(b.begin(), b.end());
        ll digit = 0;
        for(int j = 0; j < n; j++)
        {
            a[j] &= tmp*2 - 1;
            digit += lower_bound(b.begin(), b.end(), 2*tmp - a[j]) - lower_bound(b.begin(), b.end(), tmp-a[j]);
            digit += lower_bound(b.begin(), b.end(), 4*tmp - a[j]) - lower_bound(b.begin(), b.end(), 3*tmp-a[j]);
        }
        if(digit % 2 == 1)
        {
            ans += tmp;
        }
    }
    cout << ans << endl;
}
