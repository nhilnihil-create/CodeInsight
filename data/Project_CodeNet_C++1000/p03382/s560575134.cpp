#include <bits/stdc++.h>

using namespace std;

#define int long long
#define N 100005
#define MOD 1000000007


int32_t main()
{

    int n;
    cin>>n;

    vector < int > a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];

    sort(a.begin(), a.end());

    cout<<a[n-1]<<" ";

    int x = 0;
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        int cur = min(a[i], a[n-1]-a[i]);
        if ( cur > x)
        {
            x = cur;
            ans = a[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}