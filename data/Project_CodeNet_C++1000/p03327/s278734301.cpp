#include <iostream>
using namespace std;
int x;
int main() {
  cin >> x;
  if (x <= 999)
  {
      cout << "ABC" << endl;
  }
  else if(x > 999){
      cout << "ABD" << endl;
  }
  return 0;
}