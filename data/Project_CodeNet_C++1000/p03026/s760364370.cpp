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

void dfs(vector<vector<int>> &tree, vector<int> &ans, int now, int bf, int &index){
  for(auto nx : tree.at(now)){
    if(nx == bf) continue;
    ans.at(nx) = index++;
    dfs(tree, ans, nx, now, index);
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
  rep(i, n) cin >> c.at(i);
  sort(ALL(c), greater<int>());
  vector<int> ans(n, 0);
  ans.at(0) = 0;
  int index = 1;
  dfs(tree, ans, 0, -1, index);
  ll sum = 0;
  rep2(i, 1, n) sum += c.at(i);
  cout << sum << endl;
  rep(i, n){
    if(i != 0) cout << " ";
    cout << c.at(ans.at(i));
  }
  cout << endl;
  return 0;
}