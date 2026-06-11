#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fi first
#define se second
int main()
{
    ll n,m,i;
    cin>>n>>m;
    string s;
    cin>>s;
    vector<int> color(n);
    for(i=0;i<n;i++)
    {
        color[i]=(s[i]=='A');
    }
    vector<vector<ll>> g(n);
    vector<vector<ll>> deg(n,vector<ll>(2,0));
    while(m--)
    {
        ll x,y;
        cin>>x>>y;
        x--;y--;
        g[x].pb(y);
        g[y].pb(x);
        deg[x][color[y]]++;
        deg[y][color[x]]++;
    }
    vector<ll> q;
    vector<ll> was(n,0);
    for(i=0;i<n;i++)
    {
        if(deg[i][0]==0||deg[i][1]==0) 
        {
            q.pb(i);
            was[i]=1;
        }
    }
    
    for(i=0;i<q.size();i++)
    {
        for(ll j:g[q[i]])
        {
            deg[j][color[q[i]]]--;
            if(deg[j][0]==0||deg[j][1]==0)
            {
                if(!was[j])
                {
                    was[j]=1;
                    q.pb(j);
                }
            }
        }
    }
    cout<<((q.size()==n)?"No":"Yes");
    return 0;
}