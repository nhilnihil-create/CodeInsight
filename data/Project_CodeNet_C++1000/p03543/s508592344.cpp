#include <bits/stdc++.h>
using namespace std;

int main() {
  int x;
  cin >> x;
  
  int a1, a2, a3, a4;
  
  a1 = x/1000;
  a2 = (x%1000)/100;
  a3 = (x%100)/10;
  a4 = x%10;
  cout << ((a2 != a3)? "No" : ((a1 == a2 || a4 == a2)? "Yes" : "No")) << endl;
}
