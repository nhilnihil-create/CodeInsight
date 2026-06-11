#include <bits/stdc++.h>
using namespace std;

int main() {
  using pp=pair<int,int>;
  vector<pp> V(4);
  pp a, b, c, d, t, tmp;
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  V[0].first=x1;
  V[0].second=y1;
  V[1].first=x2;
  V[1].second=y2;
  t.first = V[1].first - V[0].first;
  t.second = V[1].second - V[0].second;
  tmp=t;
  for (int i=0; i<2; i++) {
    tmp.first = V[i+1].first - V[i].first;
    tmp.second = V[i+1].second - V[i].second;
    t.first=-tmp.second;
    t.second=tmp.first;
    V[i+2].first=V[i+1].first+t.first;
    V[i+2].second=V[i+1].second+t.second;
  }
  cout << V[2].first << " " << V[2].second << " " << V[3].first << " " << V[3].second << endl;
} 
