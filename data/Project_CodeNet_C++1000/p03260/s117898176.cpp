//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
using namespace std;

int main()
{
    fast_io
    ll i,j,a,b,k;
    bool found=0;
    string s;
    cin>>a>>b;
    for(i=1; i<=3; i++)
    {
        ll x=a*b*i;
        if(x%2)
            return cout<<"Yes"<<endl,0;

    }

    return cout<<"No"<<endl,0;
    return 0;
}



