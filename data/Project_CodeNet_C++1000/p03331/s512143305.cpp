#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

using namespace std;

int dig (int x)
{
    int r=0;
    while (x)
    {
        r+=x%10;
        x/=10;
    }
    return r;
}

main()
{
    fast;
    int n,i,ans=INT_MAX;
    cin>>n;
    for (i=1;i<n;i++)
        ans=min(ans,dig(i)+dig(n-i));
    cout<<ans<<endl;
}