#include <iostream>
using namespace std;

int main(){
  double a, b, x;
  cin >> a >> b;
  if(((a+b)/2) > (int)((a+b)/2)){
    cout << (int)((a+b)/2) + 1 << endl;
  }else{
    cout << (int)((a+b)/2) << endl;
  }


  return 0;
}