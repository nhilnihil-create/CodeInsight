#include <bits/stdc++.h>
using namespace std;
using P=pair<int,int>;
int main(){
  int n; cin>>n;
  vector<P> c(n),tr(n);
  vector<vector<int>> tree(n);
  for(int i=0;i<n;i++){
    c[i]=P(0,i);
  }
  for(int i=0;i<n-1;i++){
    int a,b; cin>>a>>b;
    a--; b--;
    tree[a].push_back(b);
    tree[b].push_back(a);
    tr[i]=P(a,b);
    c[a].first++; c[b].first++;
  }
  sort(c.rbegin(),c.rend());
  vector<int> weight(n),m(n);
  for(int i=0;i<n;i++){
    cin>>m[i];
  }sort(m.rbegin(),m.rend());
  queue<int> que;
  que.push(c[0].second);
  vector<bool> vis(n,false);
  int j=1; weight[c[0].second]=m[0];
  while(!que.empty()){
    int z=que.front(); que.pop();
    vis[z]=true;
    for(int i=0;i<tree[z].size();i++){
      if(vis[tree[z][i]]) continue;
      que.push(tree[z][i]);
      vis[tree[z][i]]=true;
      weight[tree[z][i]]=m[j];
      j++;
    }
  }
  long long sum=0;
  for(int i=0;i<n-1;i++){
    int x=tr[i].first,y=tr[i].second;
    sum+=min(weight[x],weight[y]);
  }cout<<sum<<endl;
  for(int i=0;i<n-1;i++){
    cout<<weight[i]<<' ';
  }cout<<weight[n-1]<<endl;
}