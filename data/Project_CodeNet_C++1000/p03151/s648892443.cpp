#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool compare( pair<ll,ll> a , pair<ll,ll> b)
{
    return (a.first - a.second) < (b.first - b.second);
}
int main()
{
    ll n;
    cin>>n;
    ll a[n] , b[n];
    ll suma = 0 ,   sumb = 0;
    pair<ll , ll > arr[n];
    set<ll> s;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        suma += a[i];
        s.insert(a[i]);
        arr[i].first = a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
        sumb += b[i];
        arr[i].second = b[i];
    }
    if( sumb > suma)
    {
        cout<<-1;
        return 0;
    }
    sort( arr,arr +n, compare );
    ll ans =0;
    ll l =0 , r= n-1;
    while( l<r)
    {
        if( arr[l].first >= arr[l].second ) {
            l++;
            continue;
        }
        if( arr[l].first < arr[l].second )
        {
            ll val1 = arr[l].second - arr[l].first;
            ll val2 = arr[r].first - arr[r].second ;
            if( val2 > val1)
            {
                arr[r].first -= val1;
                arr[l].first += val1;
                l++;
                ans++;
            }
            else if( val1 > val2)
            {
                arr[r].first -= val2;
                arr[l].first += val2;
                ans++;
                r--;
            }
            else if( val1 == val2)
            {
                arr[r].first -= val2;
                arr[l].first += val2;
                ans += 2;
                r--;
                l++;
            }
        }
    }
    if(ans)
cout<<ans+1;
   else cout<<ans;

}