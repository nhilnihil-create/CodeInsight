#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n;
    cin>>n;
    vector<ll> a(n), b(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b[i] = a[i];
    }
    sort( b.begin() , b.end() );
    for(int i=0;i<n;i++)
    {
        auto  l1 = lower_bound(b.begin() , b.end() , a[i] );
        if( l1 - b.begin() >= n/2 )
            cout<<b[n/2 - 1 ]<<endl;
        else cout<<b[n/2 ]<<endl;
    }
}