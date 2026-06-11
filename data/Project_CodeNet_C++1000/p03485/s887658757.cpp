#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b;
  int x = 0;
  cin >> a >> b;
  if((a+b)%2*10/2 >= 5){
    x = 1;
  }
  cout << (a+b)/2 + x << endl;
  return 0;
}