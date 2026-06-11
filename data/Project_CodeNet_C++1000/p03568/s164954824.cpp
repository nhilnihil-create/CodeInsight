#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
  #include "_DEBUG.hpp"
#endif
#define int long long
const int INF = 1LL << 60;

signed main(){

  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  int ans = 0;
  auto dfs = [&](auto&& dfs, int i, int sum)->void{
    if(i == n){
      ans += sum%2 == 0;
      return;
    }
    dfs(dfs, i+1, sum * (a[i]-1));
    dfs(dfs, i+1, sum * a[i]);
    dfs(dfs, i+1, sum * (a[i]+1));
  };
  dfs(dfs, 0, 1);
  cout << ans << endl;

  return 0;
}