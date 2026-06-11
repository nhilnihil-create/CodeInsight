#include <iostream>

using namespace std;

int main() {

  int n;
  cin >> n;
  if(n < 1200){
    cout << "ABC";
  }else if(n < 2800){
    cout << "ARC";
  }else{
    cout << "AGC";
  }
  return 0;
}
