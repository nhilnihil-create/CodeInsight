#include<bits/stdc++.h>
using namespace std;
long long int dis[10000000];
bool vis[10000000];
vector < long long int> adj[1000000];




long long int dfs(int n)
{
vis[n]=true;

long long int max1=0;
for(int it: adj[n])
{if(!vis[it])max1=max(max1,dfs(it)+1);
else{max1=max(max1,dis[it]+1);}
}
dis[n]=max1;
//cout<<max1<<" "<<n<<endl;
return max1;
}


main(){
long long n,m;
cin>>n>>m;
for(int i=0,a,b;i<m;i++)
{cin>>a>>b;
adj[a-1].push_back(b-1);
}

memset(vis,false,sizeof(vis));
for(int i=0;i<n;i++)
{if(!vis[i])dis[i]=dfs(i);}
long long int mx=0;
for(int i=0;i<n;i++)
mx=max(mx,dis[i]);
cout<<mx;
}
