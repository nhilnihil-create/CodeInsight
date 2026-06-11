#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
//const int MOD=998244353;
const int INF=1e9;
const long long LINF=1e18;
#define int long long
//template
template <typename T>
void fin(T a){
  cout<<a<<endl;
  exit(0);
}
//main
signed main(){
  int N,M;cin>>N>>M;
  string s;cin>>s;
  std::vector<int> edge[N],r(N,0),b(N,0);
  while(M--){
    int u,v;cin>>u>>v;u--;v--;
    edge[u].push_back(v);
    edge[v].push_back(u);
    if(s[u]=='A')r[v]++;else b[v]++;
    if(s[v]=='A')r[u]++;else b[u]++;
  }
  queue<int> que;
  std::vector<int> dele(N,0);
  for(int i=0;i<N;i++)if(r[i]*b[i]==0)que.push(i);
  while(que.size()){
    int p=que.front();que.pop();
    if(dele[p]++)continue;
    for(int q:edge[p]){
      if(dele[q])continue;
      if(s[p]=='A')r[q]--;else b[q]--;
      if(r[q]*b[q]==0)que.push(q);
    }
  }
  for(int i=0;i<N;i++)if(!dele[i])fin("Yes");
  fin("No");
}
