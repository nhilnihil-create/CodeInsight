#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
 
int main() {
  // input
  int n,m;cin >> n >> m;
  vector<int> l(m),r(m);
  for(int i = 0;i < m; i++) cin >> l[i] >> r[i]; 
 
  // compute 
  int ans;
  sort(l.begin(), l.end() ,greater<int>());
  sort(r.begin(), r.end() );
  ans = max((r.at(0) - l.at(0) + 1),0);
  
  // output  
  cout << ans << endl;
  
}