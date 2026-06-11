#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int x = 0;
  if (abs(a-c)<=d) {
    cout << "Yes" << endl;
    x++;
  }
  else {
    if (abs(a-b)<=d && abs(b-c) <=d){
      cout << "Yes" << endl;
      x++;
    }
  }
  if(x==0) {
    cout << "No" << endl;
  }
}
    