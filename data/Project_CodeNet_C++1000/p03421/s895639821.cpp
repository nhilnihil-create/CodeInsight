#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)

int main(){
  int n, a, b;
  cin >> n >> a >> b;
  int c = n - a - b + 1;
  if(c < 0 || (b == 1 && c > 0)) {
    cout << -1 << endl;
    return 0;
  }
  vector<int> ans;
  rep(i,a) ans.push_back(n-a+i+1);
  rep(i,b-1) ans.push_back(b-i-1);
  if(b == 1) {
    for(auto k: ans) cout << k << " ";
    cout << endl;
    return 0;
  }
  int d = (c+b-2)/(b-1);
  if(d > a-1) {
    cout << -1 << endl;
    return 0;
  }
  int p = 2*b - 2;
  int f = 0;
  while(ans.size() < n) {
    p = min(n-a,p);
    ans.push_back(p);
    p--; f++;
    if(f % (b-1) == 0) p += 2*b-2;
  }
  for(auto k : ans) cout << k << " ";
  cout << endl;
  return 0;
}