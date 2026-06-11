#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

using namespace std;

main()
{
    fast;
    int n,i;
    cin>>n;
    ll a[n+1];
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]-=i;
    }
    sort(a+1,a+n+1);
    ll b=a[n/2+1],ans=0;
    for (i=1;i<=n;i++)
        ans+=abs(a[i]-b);
    cout<<ans<<endl;
}