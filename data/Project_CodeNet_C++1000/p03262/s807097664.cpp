#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * b / gcd(a, b); }

#define fi first
#define se second

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,x;cin>>n>>x;

    vector<int> ix(n);
    for(int i=0;i<n;i++)cin>>ix[i];

    sort(ix.begin(),ix.end());

    map<int,int> m;

    if(ix[0]>x)m[ix[0]-x]++;

    vector<int> xx;

    for(int i=1;i<n;i++)
    {
        if(ix[i-1]<x&&x<ix[i])
        {
            xx.push_back(ix[i]-x);
            xx.push_back(x-ix[i-1]);
        }
        m[ix[i]-ix[i-1]]++;
    }
    if(ix[n-1]<x)m[x-ix[n-1]]++;

    int ans=(*m.begin()).fi;

    for(auto mm:m)
    {
        ans=gcd(ans,mm.fi);
    }

    if(xx.size()>0)ans=max(gcd(ans,xx[0]),gcd(ans,xx[1]));

    cout<<ans<<"\n";

    return 0;
}
