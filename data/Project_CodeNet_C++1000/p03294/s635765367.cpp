//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
using namespace std;

int main()
{
    fast_io
    ll i,j,n,x,ans=0;
    string s,t;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>x;
        ans+=x-1;
    }


   cout << ans<<endl;
    return 0;
}



