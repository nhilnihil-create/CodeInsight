#include<bits/stdc++.h>
#define int long long
using namespace std;


vector<set<int> >adj;
int deg[100005];
set<pair<int,int> >s;
int ans[100005];

signed main()
{
 
ios_base::sync_with_stdio(false);
cin.tie(NULL);  
cout.tie(0);   
 
#ifndef ONLINE_JUDGE
    if(fopen("INPUT.txt","r"))
    {
    freopen ("INPUT.txt" , "r" , stdin);
    freopen ("OUTPUT.txt" , "w" , stdout);
    }
#endif      

    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    int x,y;
    for(int i=0;i<n-1+m;i++)
    {
        cin>>x>>y;
        adj[x].insert(y);
        deg[y]++;
    }
    for(int i=1;i<=n;i++)
    {
        s.insert({deg[i],i});
    }

    while (!s.empty())
    {
        pair<int,int>pp=*s.begin();
        s.erase(s.begin());
        for(auto j:adj[pp.second])
        {
                s.erase({deg[j],j});
                deg[j]--;
                if(deg[j]==0)
                    ans[j]=pp.second;
                s.insert({deg[j],j});
        }
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<'\n';
    

}
