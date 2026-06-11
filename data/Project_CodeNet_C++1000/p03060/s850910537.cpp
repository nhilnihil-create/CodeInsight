#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);

    ll n;
    cin >> n;
    pair<ll,ll> arr[n];
    for (ll i=0;i<=n-1;i++)
    {
        cin >> arr[i].first;
    }
    for (ll i=0;i<=n-1;i++)
    {
        cin >> arr[i].second;
    }

    ll ans=0;
    for (ll i=0;i<=n-1;i++)
    {
        if (arr[i].second<arr[i].first)
        {
            ans=ans+arr[i].first-arr[i].second;
        }
    }
    cout << ans << endl;

    return 0;
}