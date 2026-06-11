//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
using namespace std;

int main()
{
    fast_io
    ll i,t,n,j,inc,ans=0;
    string s;
    cin>>s>>inc;
    for(i=0;i<s.length(); i+=inc)
    {
        cout<<s[i];
    }
        cout<<endl;
    return 0;
}



