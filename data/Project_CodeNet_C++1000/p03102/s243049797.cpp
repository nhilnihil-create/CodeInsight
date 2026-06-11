#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,m,c;
  cin >> n >> m >> c;
  vector<int> list(m);
  for(int i=0; i<m; i++) {
    cin >> list.at(i);
  }
  int x,y,ans=0;
  for(int i=0; i<n; i++) {
    x = c;
    for(int j=0; j<m; j++) {
      cin >> y;
      x += y*list.at(j);
    }
    if(x > 0) {
      ans++;
    }
  }
  cout << ans << endl;
}