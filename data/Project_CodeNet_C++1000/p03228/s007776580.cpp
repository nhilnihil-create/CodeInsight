#include <iostream>
using namespace std;

int main(void){
  long long a,b;
  int k;
  
  cin >> a >> b >> k;
  for (int i=0; i<k; i++){
    int x,y;
    x = a; y = b;
    a = x/2;
    b = x/2 + y;
    if (++i>=k) break;
    x = a; y = b;
    a = x + y/2;
    b = y/2;
  }
  cout << a << " " << b << endl;
  return 0;
}