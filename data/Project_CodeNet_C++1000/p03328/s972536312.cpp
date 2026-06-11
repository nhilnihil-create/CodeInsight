#include <bits/stdc++.h>
using namespace std;

int main () {

  int a, b;
  cin >> a >> b;
  
  int a_b = b-a;
  int h = 0;
  for (int i = 1; i<a_b; i++) h += i;
  
  cout << h-a << endl;
}