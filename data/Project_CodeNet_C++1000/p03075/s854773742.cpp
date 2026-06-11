#include <iostream>
using namespace std;

int main(){
  int a, b, c, d, e, k;
  cin >> a >> b >> c >> d >> e >> k;
  
  if(e-d>k || e-c>k || e-b>k || e-a>k){
    cout << ":(" << endl;
  } else if(d-c>k || d-b>k || d-a>k){
    cout << ":(" << endl;
  } else if(c-b>k || c-a>k){
    cout << ":(" << endl;
  } else if(b-a>k){
    cout << ":(" << endl;
  } else {
    cout << "Yay!" << endl;
  }
  return 0;
}