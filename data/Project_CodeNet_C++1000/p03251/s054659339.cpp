#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  vector<int> xc(n), yc(m);
  for(int i = 0; i < n; ++i) cin >> xc.at(i);
  for(int i = 0; i < m; ++i) cin >> yc.at(i);
  
  sort(xc.begin(), xc.end());
  sort(yc.begin(), yc.end());
  int s = max(x, xc.at(n-1));
  int t = min(y, yc.at(0));
  
  if(s >= t) cout << "War" << endl;
  else cout << "No War" << endl;
}