#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> tree(n, vector<int>());
  vector<int> indeg(n, 0);
  rep(i, n-1+m){
    int a, b;
    cin >> a >> b;
    a--; b--;
    tree.at(a).push_back(b);
    indeg.at(b)++;
  }
  vector<int> ans(n, -1);
  int root = -1;
  rep(i, n){
    if(indeg.at(i) == 0) root = i;
  }

  queue<int> q;
  q.push(root);
  while(!q.empty()){
    int now = q.front(); q.pop();
    for(int nx : tree.at(now)){
      indeg.at(nx)--;
      if(indeg.at(nx) == 0){
        ans.at(nx) = now;
        q.push(nx);
      }
    }
  }
  for(auto i : ans){
    cout << i+1 << endl;
  }
  return 0;
}