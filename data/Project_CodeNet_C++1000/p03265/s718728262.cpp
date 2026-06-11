#include<bits/stdc++.h>
using namespace std;

int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  
  int p = x2+(y1-y2);
  int q = y2+(x2-x1); 
  int r = x1+(y1-y2);
  int s = y1+(x2-x1);
  cout << p << " " <<  q << " " << r << " " << s << endl;
}