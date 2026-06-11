#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,d;
  1<=a,b,c,d<=10;
  cin>>a>>b>>c>>d;

  if (a+b>c+d) {
    cout << "Left" << endl;
  }
  else if (a+b==c+d) {
    cout << "Balanced" << endl;
  }
  else {
    cout << "Right" << endl;
  }
}
