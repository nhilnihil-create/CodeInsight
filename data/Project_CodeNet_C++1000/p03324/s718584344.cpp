#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;
int main(){
  int d , n;
  cin >> d >> n;
  if (n == 100) {
    n ++;
  }
  cout << fixed << setprecision(10) << (int) pow(100 , d ) * n << endl;
}