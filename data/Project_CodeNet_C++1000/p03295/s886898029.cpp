#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,m;cin>>n>>m;
    vector<pair<int,int>> p(m);
    for(int i=0;i<m;i++)
    {
        int a,b;cin>>a>>b;
        p[i]=make_pair(a,b);
    }

    sort(p.begin(),p.end());

    int ans=0;
    int nmax=p[0].se;
    for(int i=1;i<m;i++)
    {
        if(p[i].fi>=nmax)
        {
            ans++;
            nmax=p[i].se;
        }
        nmax=min(nmax,p[i].se);
    }
    ans++;

    cout<<ans<<"\n";

    return 0;
}
