#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; typedef long long ll;
typedef pair<ll,ll> P;

int main() {
  int n; cin>>n;
  vector<int> u(n); fill(u.begin(),u.end(),-1);
  vector<vector<int>> v(n);
  for(int i=0;i<n-1;i++) {
    int a,b; cin>>a>>b; a--; b--; v[a].push_back(b); v[b].push_back(a);
  }
  vector<P> c(n);
  for(int i=0;i<n;i++) cin>>c[i].first;
  for(int i=0;i<n;i++) c[i].second=i;   
  sort(c.begin(), c.end(), greater<P>());
  queue<int> que; vector<bool> us(n); us[0]=true;
  int ii=0; que.push(0); ll sm=0;
  for(int i=0;i<n;i++) {
    int nx=que.front(); que.pop();
    u[nx]=c[i].first;
    for(int x:v[nx]) {
      if (us[x]==0) que.push(x), us[x]=true;
      if (u[x]!=-1) sm+=min(u[nx], u[x]);
    }
  }
  cout<<sm<<endl;
  for(int i=0;i<n;i++) cout<<u[i]<<" "; cout<<endl;
}
