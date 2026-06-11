#include <bits/stdc++.h>

using std::cerr;
using std::endl;

typedef long long ll;

inline ll rd(){
  ll x; scanf("%lld",&x);
  return x;
}

const int N=1e5+233;

int n;
ll D[N],S[N];
std::vector<std::pair<int,int>>ans;
std::map<ll,int>map;
std::vector<int> T[N];

ll dfs(int x,int fa,int dis){
  ll ret=dis;
  for(int y:T[x]) if(y!=fa)
    ret+=dfs(y,x,dis+1);
  return ret;
}

int main(){
  //freopen("data","r",stdin);
  n=rd();
  for(int i=1;i<=n;++i){
    D[i]=rd();
    S[i]=1;
    map[-D[i]]=i;
  }
  while(!map.empty()){
    if(map.size()==1)
      break;
    int x=map.begin()->second;
    map.erase(map.begin());
    std::map<ll,int>::iterator it;
    it=map.find(-(D[x]-n+2*S[x]));
    if(it==map.end()){
      puts("-1");
      return 0;
    }
    S[it->second]+=S[x];
    ans.push_back({x,it->second});
    T[x].push_back(it->second);
    T[it->second].push_back(x);
  }
  int root=map.begin()->second;
  if(dfs(root,0,0)!=D[root]){
    puts("-1");
    return 0;
  }
  for(int i=0;i<n-1;++i)
    printf("%d %d\n",ans[i].first,ans[i].second);
  return 0;
}
