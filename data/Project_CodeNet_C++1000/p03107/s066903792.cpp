#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    string s;
    cin>>s;
    int r =0 , b = 0;
    for(int i=0;i<s.length();i++)
    {
        if( s[i] == '0')
            r++;
        else b++;
    }
    ll ans = min( r,b)*2;
    cout<<ans;
}