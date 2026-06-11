#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const ll INF = 1LL<<60;

int main(){
  int n,m,x; cin >> n >> m >> x;

  vector<int> g(n+1, 0);
  for(int i = 0; i < m; i++){
    int p; cin >> p;
    g[p] = 1;
  }
  int left = 0;
  for(int i = 0; i <= x; i++){
    left += g[i];
  }
  int right = 0;
  for(int i = x; i <= n; i++){
    right += g[i];
  }
  int ans = min(left, right);
  cout << ans << endl;
  return 0;
}
