#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

vector<int> to[10005];
vector<int> ans_index;
void dfs(int v, int p=-1) {
  ans_index.push_back(v);
  for (int u : to[v]) {
    if (u == p) continue;
    dfs(u,v);
  }
}

int main() {
  int n;
  cin >> n;
  rep(i,n-1) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  vector<int>c(n);
  rep(i,n)cin>>c[i];
  sort(c.rbegin(),c.rend());
  dfs(0);
  ll ansv=0;
  rep(i,n-1)ansv+=c[i+1];
  cout << ansv << endl;
  vector<int> ans(n);
  rep(i,n){
    ans[ans_index[i]]=c[i];
  }
  rep(i,n) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
