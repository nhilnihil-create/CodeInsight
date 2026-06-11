#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  
  int a, b ,c, d;
  a = n % 10;
  b = n % 100 / 10;
  c = n % 1000 / 100;
  d = n / 1000;
  
  if((a == b && b == c) || (b == c && c == d)){
    cout << "Yes" << endl;
  }else cout << "No" << endl;
}