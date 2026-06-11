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
  int n;
  cin >> n;
  vector<vector<int>> tree(n, vector<int>());
  rep(i, n-1){
    int a, b;
    cin >> a >> b;
    a--; b--;
    tree.at(a).push_back(b);
    tree.at(b).push_back(a);
  }
  vector<int> c(n);
  rep(i, n) cin >> c.at(i);
  sort(ALL(c), greater<int>());
  ll sum = 0;
  vector<int> ans(n, -1);
  int index = 1;
  ans.at(0) = c.at(0);
  queue<int> q;
  q.push(0);
  while(!q.empty()){
    auto i = q.front(); q.pop();
    for(int nx : tree.at(i)){
      if(ans.at(nx) != -1) continue;
      ans.at(nx) = c.at(index);
      sum += ans.at(nx);
      index++;
      q.push(nx);
    }
  }
  cout << sum << endl;
  rep(i, n){
    if(i != 0) cout << " ";
    cout << ans.at(i);
  }
  cout << endl;
  return 0;
}