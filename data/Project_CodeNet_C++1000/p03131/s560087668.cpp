#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll k,a,b;
    cin>>k>>a>>b;

    if( b - a <= 2)
    {
        cout<<1+k;
    } else
    {
        if( k <= a)
        {
            cout<<1+k;
        } else
        {
            ll ans = a;
            k = k - a + 1;
            ll temp = k/2;
            ans += temp*(b-a);
            if( k%2)
                ans++;
            cout<<ans;
        }
    }

}