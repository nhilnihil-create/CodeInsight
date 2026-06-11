#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin>>n;
    ll m =0,a=0,r=0,c=0,h=0;
    for(int i=0;i<n;i++)
    {
        string temp;
        cin>>temp;
        if( temp[0] == 'M')
            m++;
        if( temp[0] == 'A')
            a++;
        if( temp[0] == 'R')
            r++;
        if( temp[0] == 'C')
            c++;
        if( temp[0] == 'H')
            h++;
    }
    ll ans = 0;
    ans += m*a*r;
    ans += m*a*c;
    ans += m*a*h;
    ans += m*r*c;
    ans += m*r*h;
    ans += a*r*c;
    ans += a*r*h;
    ans += a*c*h;
    ans += r*c*h;
    ans += m*c*h;
    cout<<ans;

}