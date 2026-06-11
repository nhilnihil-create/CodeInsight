#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> p(n);
  for(int i = 0; i < n; i++) cin >> p[i];
  int ans = accumulate(p.begin(), p.end(), 0) - *max_element(p.begin(), p.end()) / 2;
  cout << ans << endl;
  return 0;
}