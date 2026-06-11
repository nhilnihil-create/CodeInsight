#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;cin>>n;

    map<int,int> m;
    for(int i=0;i<n;i++)
    {
        int a;cin>>a;
        m[a]++;
    }

    int ans=0;

    for(auto mm:m)
    {
        if(mm.fi>mm.se)ans+=mm.se;
        else if(mm.fi<mm.se)ans+=mm.se-mm.fi;
    }

    cout<<ans<<"\n";

    return 0;
}
