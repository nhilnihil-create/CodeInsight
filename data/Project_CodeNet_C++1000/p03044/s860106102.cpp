#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define  optimize   ios::sync_with_stdio(0); cin.tie(0);
#define PI  acos(-1.0)
#define RESET(a, b) memset(a, b, sizeof(a))
#define pb push_back
int n;
vector<int> g[100001];
map<int,map<int,int> > cost;
int vis[100001];
map<int,int>clr;
void bfs(int s){
   queue<int>q;
   q.push(s);
   vis[s]=1;
   clr[s]=0;
   while(q.size()>0){
     int top=q.front();
     q.pop();
     for(int i=0;i<g[top].size();i++){
        int x=g[top][i];
        if(vis[x]==0){
          if(clr[top]==0){
            if(cost[top][x]%2==0) clr[x]=0;
            else clr[x]=1;
          }
          else{
            if(cost[top][x]%2==0) clr[x]=1;
            else clr[x]=0;
          }
          q.push(x);
          vis[x]=1;
        }
     }
   }
}
int main()
{
     optimize
     cin>>n;
     for(int i=1;i<n;i++){
        int x,y,w;
        cin>>x>>y>>w;
        g[x].pb(y);
        g[y].pb(x);
        cost[x][y]=cost[y][x]=w;
     }
     RESET(vis,0);
     bfs(1);
     //cout<<clr[7]<<endl;
     for(int i=1;i<=n;i++) cout<<clr[i]<<" ";
}
