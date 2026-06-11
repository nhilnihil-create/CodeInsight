#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c, d;
  string s;
  cin >> a >> b >> c >> d;
  if ((a+b) == (c+d)) s = "Balanced";
  else if ((a+b) < (c+d)) s = "Right";
  else s = "Left";
  cout << s << endl;  
}