#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> t(n+1,0),x(n+1,0),y(n+1,0);
  for(int i=1; i<n+1; i++) {
    cin >> t[i] >> x[i] >> y[i];
    int dt=t[i]-t[i-1];
    int dx=abs(x[i]-x[i-1]);
    int dy=abs(y[i]-y[i-1]);
    if(dt%2==(dx+dy)%2 && dt>=(dx+dy)) continue;
    else {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}