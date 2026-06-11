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
   
    ll sum=0;
    ll min_val=LLONG_MAX;
    ll count=0;
    for (ll i=0;i<=n-1;i++)
    {
        ll a;
        cin >> a;
        sum=sum+abs(a);
        min_val=min(min_val,abs(a));

        if (a<0)
        {
            count++;
        }
    }

    if (count%2==0)
    {
        cout << sum << endl;
    }
    else
    {
        cout << sum-2*min_val << endl;
    }

    return 0;
}