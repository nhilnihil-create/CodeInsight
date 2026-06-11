#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d;
  e=a+b;
  f=c+d;
  if (e>f){
    cout << "Left" << endl;
  }
  else if (e<f){
    cout << "Right" << endl;
  }
  else{
    cout << "Balanced" << endl;
  }
}