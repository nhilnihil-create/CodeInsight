#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long a[100100];

int main()
{
    int n,i;
    long long ans=2,sum=2;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(i=n;i>0;i--)
    {
        if(ans%a[i])
        {
            ans/=a[i];
            ans=ans*a[i]+a[i];
        }
        sum=(sum/a[i]+1)*a[i]-1;
    }
    if(ans>sum) cout << -1 << endl;
    else cout << ans << " " << sum << endl;
    return 0;
}