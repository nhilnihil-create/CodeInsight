#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

using namespace std;

main()
{
    fast;
    int n,k,a,i;
    cin>>n>>k;
    map<int,int> f;
    vector<pair<int,int>> grp;
    set<int> dist;
    for (i=0;i<n;i++)
    {
        cin>>a;
        dist.insert(a);
        f[a]++;
    }
    if (dist.size()<=k)
        cout<<"0\n";
    else
    {
        for (auto e: f)
            grp.pb(mp(e.ss,e.ff));
        sort(grp.begin(),grp.end());
        int ans=0;
        for (i=0;i<dist.size()-k;i++)
            ans+=grp[i].ff;
        cout<<ans<<endl;
    }
}