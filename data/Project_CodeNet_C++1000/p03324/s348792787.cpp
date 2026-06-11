#include <iostream>
#include <iomanip>
using namespace std;
int main(){
  int d , n , pow = 1;
  cin >> d >> n;
  for (int i = 0 ; i < d ; i ++) {
    pow *= 100;
  }
  if (n == 100) {
    n ++;
  }
  cout << pow * n << endl;
}