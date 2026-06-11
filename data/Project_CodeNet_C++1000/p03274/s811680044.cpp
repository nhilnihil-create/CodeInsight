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
    ll x[n],ans=1e10,tp;
    for (i=0;i<n;i++)
        cin>>x[i];
    for (i=0;i<n-k+1;i++)
    {
        if (x[i]<=0 && x[i+k-1]<=0)
            tp=abs(x[i]);
        else if (x[i]>=0 && x[i+k-1]>=0)
            tp=x[i+k-1];
        else
            tp=min(2*abs(x[i])+x[i+k-1],abs(x[i])+2*x[i+k-1]);
        ans=min(ans,tp);
    }
    cout<<ans<<endl;
}