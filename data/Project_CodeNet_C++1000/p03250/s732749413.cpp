#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a, b , c , d;
  cin >> a >> b >> c;
  d = max ( a, max ( b,c)) ;
  cout << ( d==b ? a+10*b+c : d==a ?10*a + b + c : a+b+10*c ) <<endl;
}