#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  
  int a;
  map<int,int> x;
  for(int i=0; i<n; i++) {
    cin >> a;
    x[a]++;
  }
  
  vector<int> y;
  for(auto p : x) y.push_back(p.second);
  sort(y.rbegin(), y.rend());
  
  int ans = 0;
  int b = y.size();
  for(int i=0; i<b; i++) {
    if(y.size()>k) {
      ans += y[y.size()-1];
      y.pop_back();
    }
    else break;
  }
  
  cout << ans << endl;
  return 0;
}