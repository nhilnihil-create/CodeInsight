#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
    
  int add = a+b;
  int sub = a-b;
  int mul = a*b;
  
  if ((add > sub) && (add > mul)) cout << add << endl;
  else if (sub > mul) cout << sub << endl;
  else cout << mul << endl;
}