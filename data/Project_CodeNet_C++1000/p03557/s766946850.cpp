#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
    ll n;
    cin >> n;
    vector<ll>a(n),b(n),c(n);
    for(ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(ll i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for(ll i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    ll ans = 0;
    for(ll i = 0; i < n; i++)
    {
        vector<ll>::iterator itr1 = lower_bound(a.begin(),a.end(),b[i]);
        vector<ll>::iterator itr2 = upper_bound(c.begin(),c.end(),b[i]);
        itr1--;
        if(itr2 == c.end())
        {
            break;
        }
        ll dis1 = distance(a.begin(),itr1);
        ll dis2 = distance(c.begin(),itr2);
        ans += (dis1 + 1)*(n - dis2);
    }
    cout << ans << endl;
}