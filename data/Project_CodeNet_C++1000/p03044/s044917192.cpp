#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct edge
{
    ll v,w;
}e1;
vector<edge>E[100005];
ll check[100005]={0},n,k;
ll color[100005];
void dfs(ll s,ll len=0)
{
    check[s]=1;
    ll sz=E[s].size();
    for(ll i=0;i<sz;i++)
    {
        ll v=E[s][i].v;
        if(check[v]==0)
        {  ll w=E[s][i].w;
            if((len+w)%2==0)
                color[v]=0;
            else
                {color[v]=1;}

                dfs(v,len+w);
                check[v]=1;
        }
    }


}
int main()
{
   ll i,u,v,w;
   cin>>n;
   for(i=0;i<n-1;i++)
   {
       cin>>u>>v>>w;
       k=u;
       e1.v=v;
       e1.w=w;
       E[u].push_back(e1);
       e1.v=u;
       E[v].push_back(e1);


   }
   color[1]=0;
   dfs(1);
   for(i=1;i<=n;i++)
    cout<<color[i]<<endl;

}
