#include <iostream>
using namespace std;
int main() {
  int n,m,x,y;
  cin >> n >> m >> x >> y;
  for (int i = 0; i < n; i++) {
    int xi;
    cin >> xi;
    x = max(x,xi);
  }
  for (int i = 0; i < m; i++) {
    int yi;
    cin >> yi;
    y = min(y,yi);
  }
  if (x < y) cout << "No War" << endl;
  else cout << "War" << endl;
  return 0;
}