#include <iostream>
using namespace std;
int main(void){
  int a,b;
  cin >> a >> b;
  
  if((a + 1) / 2 >= b)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  
  return 0;
}
