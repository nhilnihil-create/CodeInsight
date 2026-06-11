#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main()
{
    fast_io
    ll i,j,n;
    cin>>n;
    ll a[n];
    ll cost=0,prev=0,ans;
    for(i=0; i<n; i++)
    {
        cin>>a[i];
        cost+=abs(prev-a[i]);
        prev=a[i];
    }
    cost+=abs(a[n-1]);
    prev=0;
    for(i=0; i<n; i++)
    {
        ans=cost;
        if(i==n-1)

            ans=ans-abs(a[i]-prev)-abs(a[i])+abs(a[i-1]);
        else
            ans=ans-abs(a[i]-prev)-abs(a[i+1]-a[i])+abs(a[i+1]-prev);
        prev=a[i];
        cout<<ans<<endl;

    }

    return 0;
}



