#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b; cin >> a >> b;
  vector<int>v{a+b,a-b,a*b};
  sort(v.begin(),v.end());
  int ans = v[2];
  cout << ans << endl;
  
  return 0;
}