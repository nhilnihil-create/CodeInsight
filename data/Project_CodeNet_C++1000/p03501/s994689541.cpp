#include <iostream>
#include <math.h>
using namespace std;
#define prt(var) cout << (var) << endl;

int main() {
  int n, a, b;
  cin>>n>>a>>b;
  
  prt(min(a*n, b));
}