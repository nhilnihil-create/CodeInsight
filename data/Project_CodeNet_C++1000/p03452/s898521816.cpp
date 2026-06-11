#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std; typedef long long ll; const ll INF=1e18;
typedef pair<int,int> P;

int main() {
  int n,m; cin>>n>>m;
  ll l[m], r[m], d[m];
  for(int i=0;i<m;i++) cin>>l[i]>>r[i]>>d[i];
  for(int i=0;i<m;i++) l[i]--,r[i]--;

  bool able[m]; fill(able,able+m,false);
  vector<int> c[n];
  for(int i=0;i<m;i++) {
    c[l[i]].push_back(i);
    c[r[i]].push_back(i);
  }
  queue<int> que; ll p[n]; fill(p,p+n,INF);

  bool collapsed=false;

  for(int i=0;i<m;i++) {
    if (able[i]) continue;
    able[i]=true; que.push(i); p[l[i]]=0;

    while(!que.empty()) {
      int id = que.front(); que.pop();
      int L = l[id], R = r[id], D=d[id];
      if (p[L]==INF) p[L]=p[R]-D;
      else if (p[R]==INF) p[R]=p[L]+D;
      else {
        if (p[L] + D != p[R]) collapsed = true;
      }
      for(int x:c[L]) {
        if (!able[x]) able[x]=true, que.push(x);
      }
      for(int x:c[R]) {
        if (!able[x]) able[x]=true, que.push(x);
      }
      c[L].clear(); c[R].clear();
    }

    //if (collapsed) break;
  }

  if (collapsed) cout<<"No"<<endl;
  else cout<<"Yes"<<endl;
}