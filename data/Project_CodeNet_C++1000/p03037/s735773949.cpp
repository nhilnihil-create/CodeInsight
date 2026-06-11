#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,m;
    cin>>n>>m;
    ll arr[m+5]= {0};
    ll brr[m+5]= {0};
    ll ans=0;
    for(int i=0; i<m; i++)
    {
        ll x,y;
        cin>>x>>y;
        arr[i]=x;
        brr[i]=y;
    }
    sort(arr,arr+m);
    sort(brr,brr+m,greater<ll>());
    //cout<<arr[m-1]<<" "<<brr[m-1]<<endl;
    if(brr[m-1]-arr[m-1]+1>0)
    {
        ans=brr[m-1]-arr[m-1]+1;
    }
    else
    {
        ans=0;
    }
    cout<<ans<<endl;
}
