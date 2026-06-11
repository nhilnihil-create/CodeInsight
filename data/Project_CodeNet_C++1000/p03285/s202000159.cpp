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
    string s;
    cin>>n;
    if(n%4==0||n%7==0)
        return cout <<"Yes"<<endl,0;
    for(i=0; i<=n/4; i++)
    {
        for(j=0; j<=n/7; j++)
        {
            if(i*4+j*7==n)
                return cout <<"Yes"<<endl,0;
        }
    }
    return cout <<"No"<<endl,0;
    return 0;
}



