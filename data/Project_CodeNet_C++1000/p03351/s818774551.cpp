#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  int d1,d2,d3;
  d1=max(a,b)-min(a,b);
  d2=max(b,c)-min(b,c);
  d3=max(a,c)-min(a,c);
  if (d3<=d || (d1<=d && d2<=d)) cout << "Yes" << endl;
  else cout << "No" << endl;
}