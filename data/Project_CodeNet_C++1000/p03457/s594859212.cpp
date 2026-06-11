#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  bool travel = true;
  int a, b;
  int tn, xn, yn, tp, xp, yp;
  for(int i=0; i<n; i++) {
    cin >> tn >> xn >> yn;
    if(i==0) {
      a = tn-(abs(xn)+abs(yn));
      if(a<0 || a%2==1) travel = false;
    }
    else {
      b = (tn-tp)-(abs(xn-xp)+abs(yn-yp));
      if(b<0 || b%2==1) travel = false;
    }
    tp=tn, xp=xn, yp=yn;
  }
  
  if(travel) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}