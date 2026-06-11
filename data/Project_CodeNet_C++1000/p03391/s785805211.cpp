#include <bits/stdc++.h>

using namespace std;

#define int long long
#define N 100005
#define MOD 1000000007

int ans[N];

int32_t main()
{
    int n;
    cin>>n;

    vector < int > a(n), b(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
    }


    int maxi = 0;
    int tot = 0;

    if(a==b)
    {
        cout<<0<<endl;
    } 
    else
    {
        maxi = 1e10;
        for(int i=0;i<n;i++)
        {
            if(a[i] > b[i])
                maxi = min(maxi, b[i]);
            tot+=a[i];
        }
        cout<<tot-maxi<<endl;
    }

    return 0;
}