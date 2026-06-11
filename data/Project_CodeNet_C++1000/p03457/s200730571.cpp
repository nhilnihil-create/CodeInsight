#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main(){
  int n;
  cin >> n;
  int px=0, py=0, pt=0;
  for(int i=0; i<n; i++){
    int x, y, t;
    cin >> t >> x >> y;
    int dx = abs(px - x);
    int dy = abs(py - y);
    int dt = t - pt;
    if((dx+dy>dt)||((dx+dy)%2!=dt%2)){
      cout << "No" << endl;
      return 0;
    }
    px = x;
    py = y;
    pt = t;
  }
  cout << "Yes" << endl;
  return 0;
}
