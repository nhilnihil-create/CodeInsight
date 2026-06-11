#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define inf 1e18
#define pi acos(-1.0)
#define mod 998244353

int main(void)
{
    fastio;

    int n,c,v[25],ans=0,i;
    cin >> n;
    for(i=0;i<n;i++)cin >> v[i];
    for(i=0;i<n;i++)
    {
        cin >> c;
        if(v[i]>c)ans=ans+v[i]-c;
    }
    cout << ans ;

    return 0;
}
