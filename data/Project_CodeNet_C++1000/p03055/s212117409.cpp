#include<bits/stdc++.h>
using namespace std;

const int maxn = 200000+3;
vector<int> son[maxn];
#define mp make_pair
#define fi first
#define se second
queue<pair<int,int> > q;
bool vis[maxn];
pair<int,int> bfs(int x)
{
    while(!q.empty())   q.pop();
    memset(vis,0,sizeof vis);
    q.push(mp(x,0));
    int d=0;
    vis[x]=true;
    while(!q.empty())
    {
        x=q.front().fi; d=q.front().se;
        q.pop();
        for(auto g:son[x])
            if(!vis[g])
            {
                q.push(mp(g,d+1));
                vis[g]=true;
            }
    }
    return mp(x,d);
}
int main()
{
    ios::sync_with_stdio(false);
    int N;
    cin>>N;
    int a,b;
    #define pb push_back
    while(--N)
    {
        cin>>a>>b;
        son[a].pb(b);
        son[b].pb(a);
    }
    pair<int,int> x;
    x=bfs(1);
    x=bfs(x.fi);
    #ifdef fuckoj
    cout<<x.se<<endl;
    #endif
    if(x.se%3==1)   cout<<"Second"<<endl;
    else cout<<"First"<<endl;
    return 0;
}