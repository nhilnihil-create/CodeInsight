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
    int n,k,i;
    cin>>n>>k;
    int a[n];
    for (i=0;i<n;i++)
        cin>>a[i];
    int ans=1;
    n-=k;
    if (n%(k-1)==0)
        ans+=n/(k-1);
    else
        ans+=n/(k-1)+1;
    cout<<ans<<endl;
}