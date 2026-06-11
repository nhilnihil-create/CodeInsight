#include <iostream>
using namespace std;

int main(){
  int a;
  unsigned long u = 2, v = 1, w = 0;
  cin >> a;
  if(a == 0){
    cout << 2 << endl;
    return 0;
  }
  if(a == 1){
    cout << 1 << endl;
    return 0;
  }
  for(int i = 2; i <= a; i++){
    w = u + v; 
    u = v;
    v = w;
  }
  cout << w << endl;
}