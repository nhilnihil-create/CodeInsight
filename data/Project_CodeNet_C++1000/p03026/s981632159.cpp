#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

void dfs(vector<vector<int>> &tree, int now, vector<int> &c, vector<int> &nd, int &index, int &ans){
  for(auto i : tree.at(now)){
    if(nd.at(i) != -1) continue;
    nd.at(i) = c.at(index++);
    ans += nd.at(i);
    dfs(tree, i, c, nd, index, ans);
  }
}

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
  rep(snip_i, n) cin >> c.at(snip_i);
  sort(c.rbegin(), c.rend());
  vector<int> nd(n, -1);
  nd.at(0) = c.at(0);
  int ans = 0, index = 1;
  dfs(tree, 0, c, nd, index, ans);
  cout << ans << endl;
  rep(i, n){
    if(i != 0) cout << " ";
    cout << nd.at(i);
  }
  cout << endl;
  return 0;
}