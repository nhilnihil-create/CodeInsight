#include <iostream>
#include <iomanip>

using namespace std;

int main() {

  char a, b, c;
  cin >> a >> b;
  double ans, ra, rb;
  string dolphinManJotaro;
  if(a < b){
    cout << '<';
  }else if(a > b){
    cout << '>';
  }else{
    cout << '=';
  }
  return 0;
}
