#include<bits/stdc++.h>
#define ll long long 
#define ld long double
#define pb push_back
#define vl vector
#define ff first
#define ss second
using namespace std;
int main()
{
    ll a,b,i,j,n,t,c,m;
    cin>>n>>m;
    ll arr[n];
    for(i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    vl<pair<ll,ll>> p;
    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        p.pb({b,a});
    }
    sort(p.rbegin(),p.rend());
    j=0;
    ll flag=0;
    for(i=0;i<m;i++)
    {
        a=p[i].ss;
        b=p[i].ff;
        while(a-- && j<n)
        {
            if(arr[j]<b) arr[j]=b;
            else
            {
                flag=1;
                break;
            }
            j++;
        }
        if(flag==1 || j>=n) break;
    }
    ll sum=0;
    //for(i=0;i<n;i++) cout<<arr[i]<<" ";cout<<endl;
    for(i=0;i<n;i++) sum+=arr[i];
    cout<<sum;
}