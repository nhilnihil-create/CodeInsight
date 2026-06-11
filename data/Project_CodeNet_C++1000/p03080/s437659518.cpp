//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
using namespace std;

int main()
{
    fast_io
    ll i,j,n,red=0,blue=0;
    string s;
    cin>>n>>s;
    for(i=0; s[i]; i++)
        if(s[i]=='R')
            red++;
        else
            blue++;
    if(red>blue)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;



    return 0;
}



