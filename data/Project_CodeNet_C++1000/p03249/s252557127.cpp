#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+100;
typedef long long ll;
typedef pair<ll,int> pli;
#define fr(i,a,b) for(int i = a;i <= b; ++i)
#define nfr(i,a,b) for(int i = a;i >= b; --i)
#define pb push_back

int n;
pli v[N];
ll d[N];
int fa[N];
int siz[N];
map<ll,int> vis;

vector<int> edge[N];
ll val;

void dfs(int x,int fa,int dep){
   val += dep;
   fr(i,0,(int)edge[x].size()-1){
      int y = edge[x][i];
      if(y == fa)continue ;
      dfs(y,x,dep+1);
   }
}

int main(){
   val = 0;
   scanf("%d",&n);
   fr(i,1,n){
      scanf("%lld",d+i); v[i] = pli(d[i],i);
      vis[d[i]] = i;
   }

   sort(v+1,v+n+1,greater<pli>());
   fr(i,1,n-1){
      siz[v[i].second]++;
      ll w = v[i].first+siz[v[i].second]*2-n;
      if(!vis[w]){
         puts("-1"); return 0;
      } else {
         fa[v[i].second] = vis[w]; siz[vis[w]] += siz[v[i].second];
         edge[vis[w]].pb(v[i].second);
      }
   }

   dfs(v[n].second,0,0);
   if(val != v[n].first){
      puts("-1"); return 0;
   }
   
   fr(i,1,n-1){
      printf("%d %d\n",v[i].second,fa[v[i].second]);
   }
   return 0;
}
