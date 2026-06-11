#include<bits/stdc++.h>
using namespace std;
#define int long long
main()
{
    int n;
    cin>>n;
    int a[n+5],ans=0;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        while(a[i]%2==0)
        {
            a[i]/=2;
            ans++;
        }

    }
    cout<<ans<<endl;
}
