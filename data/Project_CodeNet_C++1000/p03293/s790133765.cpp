//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
using namespace std;

int main()
{
    fast_io
    ll i,j,lens;
    string s,t;
    char last;
    cin>>s>>t;
    lens=s.length();
    for(i=0; i<lens; i++)
    {
        string r;
        last=s[lens-1];
        r=last+s.substr(0,lens-1);
        if(t==r)
        {
            return cout << "Yes",0;
        }
        s=r;
    }
    return cout << "No",0;
    return 0;
}



