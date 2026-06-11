#include <iostream>
using namespace std;

#define MAX(X,Y) ((X)>(Y)?(X):(Y))

int main(void){
  int a,b;
  
  cin >> a >> b;
  cout << (a+b==15?"+":a*b==15?"*":"x") << endl;
  return 0;
}