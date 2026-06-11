#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int a,b,c;
  cin >> a >> b >> c;
  int x = max({a,b,c});
  cout << x*10+a+b+c-x << "\n";
  return 0;
}