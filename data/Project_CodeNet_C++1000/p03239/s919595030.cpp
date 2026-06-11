#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {

  int n,t;
  cin >> n >> t;
  
  vector<int> ans;
  
  rep(i,n) {
    int a,b;
    cin >> a >> b;
    if(b <= t) ans.push_back(a);
  }
  
  sort(ans.begin(), ans.end());
  
  if(ans.size() > 0) cout << ans[0] << endl;
  else cout << "TLE" << endl;
  
  
}
