#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using str = string;
using ss = stringstream;

ll m[5];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;cin>>n;

    for(int i=0;i<n;i++)
    {
        str s;cin>>s;

        if(s[0]=='M')m[0]++;
        else if(s[0]=='A')m[1]++;
        else if(s[0]=='R')m[2]++;
        else if(s[0]=='C')m[3]++;
        else if(s[0]=='H')m[4]++;
    }

    ll ans=0;

    ans+=m[0]*m[1]*m[2];
    ans+=m[0]*m[1]*m[3];
    ans+=m[0]*m[1]*m[4];
    ans+=m[0]*m[2]*m[3];
    ans+=m[0]*m[2]*m[4];
    ans+=m[0]*m[3]*m[4];
    ans+=m[1]*m[2]*m[3];
    ans+=m[1]*m[2]*m[4];
    ans+=m[1]*m[3]*m[4];
    ans+=m[2]*m[3]*m[4];

    cout<<ans<<"\n";

    return 0;
}
