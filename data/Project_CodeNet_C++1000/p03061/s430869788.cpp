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
    ll arr[n];
    for (ll i=0;i<=n-1;i++)
    {
        cin >> arr[i];
    }

    ll before[n];
    ll after[n];
    
    before[0]=arr[0];
    for (ll i=1;i<=n-1;i++)
    {
        before[i]=__gcd(before[i-1],arr[i]);
    }

    after[n-1]=arr[n-1];
    for (ll i=n-2;i>=0;i--)
    {
        after[i]=__gcd(after[i+1],arr[i]);
    }


    ll ans_first=after[1];
    ll ans_second=before[n-2];
    ll ans=max(ans_first,ans_second);

    for (ll i=1;i<=n-2;i++)
    {
        ll local=__gcd(before[i-1],after[i+1]);
        ans=max(ans,local);
    }

    cout << ans << endl;
    return 0;
}