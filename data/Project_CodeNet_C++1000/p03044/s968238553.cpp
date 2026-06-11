#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<ll,ll> >adj[100005];
int main()
{
    ll i,j,k,n,m,s,x,y,c=0,mid,ans;
    cin>>n;
    for(i=0;i<n-1;i++){
        cin>>x>>y>>k;
        adj[x].push_back({y,k});
        adj[y].push_back({x,k});
    } ll ind;
    for(i=1;i<n;i++){
        if(adj[i].size()==1){ind=i;break;}
    }ll xx,yy;
    bool vis[n+3]={false};
    ll a[n+5];
    a[ind]=0;
    vis[ind]=true;
    priority_queue<pair<ll,ll> >q;
    q.push({ind,a[ind]});
    while(!q.empty()){
        x=q.top().first;
        y=q.top().second;
        q.pop();
        for(auto z:adj[x]){
            xx=z.first;yy=z.second;
            if(vis[xx]) continue;
            a[xx]=yy+y;
            q.push({xx,a[xx]});
            vis[xx]=true;
        }
    }
    for(i=1;i<=n;i++){
        if(a[i]&1) printf("1\n");
        else printf("0\n");
    }
}
