#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
using namespace std;

int main()
{
    fast_io
    ll n,m,l,r,i,j,maxi=INT_MIN,mini=INT_MAX;
    cin>>n>>m;
    while(m--)
    {
        cin>>l>>r;
        maxi=max(maxi,l);
        mini=min(mini,r);
    }
    cout<<max(0*1ll,mini-maxi+1)<<endl;



    return 0;
}



