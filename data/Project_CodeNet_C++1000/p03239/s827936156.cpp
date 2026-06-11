#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
int main()
{
    ft
    ll t,i,j,n,s=LLONG_MAX,l,r;
    cin>>n>>t;
    for(i=0;i<n;i++)
    {
        cin>>l>>r;
        if(r<=t)
        {
            s=min(s,l);
        }
    }
    if(s==LLONG_MAX)
    {
        cout<<"TLE\n";
        return 0;
    }
    cout<<s<<"\n";
    return 0;
}