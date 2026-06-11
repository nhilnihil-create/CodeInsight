#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
using namespace std;
const int INF = 1e9+7;

main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin>>n;
    vector<int> a(n), b(n);
    ll sum = 0;
    bool ok = true;
    for (int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
        if (a[i]!=b[i])
            ok = false;
        sum+=a[i];
    }
    ll res = 0;
    if (ok)
    {
        cout<<res;
        return 0;
    }
    for (int i=0;i<n;i++)
    {
        if (a[i]>b[i])
        {
            res = max(res, sum-a[i] + a[i]-b[i]);
        }
    }
    cout<<res;
    return 0;
}

