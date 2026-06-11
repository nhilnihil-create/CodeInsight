#include <iostream>

using namespace std;

int main() {

  int n, odd = 1, p, ans = 0, old = 0, a, b, c;
  cin >> a >> b >> c;
  if(a + b >= c){
    cout << b + c;
  }else{
    cout << b + (a + b) + 1;
  }
  return 0;
}
