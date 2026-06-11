#include<bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,x,y; cin >> a >> b >> c >> x >> y;
  cout << min(2*c*max(x,y),a*x+b*y+min(2*c-a-b,0)*min(x,y)) << '\n';
}