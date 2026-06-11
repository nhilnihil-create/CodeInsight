#include <bits/stdc++.h>
using namespace std;

int main(){
  int R,G;
  cin >> R >> G;
  if (R<=G){
    int a,b;
    a = (G-R)*2;
    b = a+R;
    cout << b << endl;
  }
  else if (R>G) {
    int a,b;
    a = (R-G)*2;
    b = R-a;
    cout << b << endl;
  }
}