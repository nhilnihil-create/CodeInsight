#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;cin>>n;
    map<int,int> nm;
    for(int i=0;i<n;i++)
    {
        int d;cin>>d;
        nm[d]++;
    }
    int m;cin>>m;
    map<int,int> mm;
    for(int i=0;i<m;i++)
    {
        int t;cin>>t;
        mm[t]++;
    }

    bool ans=true;

    for(auto im:mm)
    {
        if(nm[im.fi]<im.se){ans=false;break;}
    }

    puts(ans?"YES":"NO");

    return 0;
}
