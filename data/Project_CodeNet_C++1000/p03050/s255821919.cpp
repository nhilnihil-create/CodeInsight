#include <bits/stdc++.h>
#define EPS 1e-9
#define PI acos(-1)
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin>>n;
    ll ans = 0;
    for(ll i = 1; i*i <= n; i++)
    {
        if(n%i==0)
        {
            if(n/i < i - 1)
            {
                ans += i-1;
                //cout<<i-1<<endl;
            }
            if(i*i==n) continue;
            if(i < n/i - 1)
            {
                ans += n/i-1;
                //cout<<n/i-1<<endl;
            }
        }
    }
    cout<<ans<<endl;
}
