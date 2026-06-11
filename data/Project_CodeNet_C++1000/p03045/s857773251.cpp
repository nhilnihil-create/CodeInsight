#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for(int i = 0; i < n; i++)

vector<int> E[100005];
bool check[100005];

void dfs(int fro, int to) {
  if (check[to] == 1) return;
  check[to] = 1;
  for(int& e:E[to]) {
    if (e != fro) dfs(to,e);
  }
}

int main() {
  int n,m,x,y,z;
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    cin >> x >> y >> z;
    E[x-1].push_back(y-1);
    E[y-1].push_back(x-1);
  }
  for(int i = 0; i < n; i++) check[i] = 0;
  int ans = 0;
  for(int i = 0; i < n; i++) {
    if (check[i] == 0) {
      ans++;
      dfs(-1,i);
    }
  }
  cout << ans << endl;
  return 0;
}
