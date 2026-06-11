#include <bits/stdc++.h>
using namespace std;

int main() {
  int D;
  cin >> D;
  string e,s;
  e =" Eve";
  s ="Christmas";
  if(D == 25)cout << s <<endl;
  if(D == 24)cout << s << e <<endl;
  if(D == 23)cout << s << e << e <<endl;
  if(D == 22)cout << s << e << e << e <<endl;
}