#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  int sum = a + b + c;
  if(sum - a == b*2) cout << a << endl;
  else if(sum-b == c*2) cout << b << endl;
  else cout << c << endl;
  return 0;
}
