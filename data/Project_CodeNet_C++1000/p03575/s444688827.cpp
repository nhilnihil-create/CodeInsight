#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<P>> v(n,vector<P>(0));
  for(int i=0; i<m; ++i){
    int a, b;
    cin >> a >> b;
    --a; --b;
    v[a].push_back(make_pair(b,i));
    v[b].push_back(make_pair(a,i));
  }
  int ans = 0;
  for(int i=0; i<m; ++i){
    queue<int> que;
    que.push(0);
    vector<bool> ok(n,false), alr(n,true);
    alr[0] = false;
    ok[0] = true;
    while(!que.empty()){
      int x = que.front();
      que.pop();
      for(auto p:v[x]){
        if(p.second == i)continue;
        if(alr[p.first]){
          que.push(p.first);
          alr[p.first] = false;
          ok[p.first] = true;
        }
      }
    }
    for(int j=0; j<n; ++j){
      if(!ok[j]){
        ++ans;
        break;
      }
    }
  }
  cout << ans << endl;
}