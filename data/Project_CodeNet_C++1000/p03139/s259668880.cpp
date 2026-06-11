#include <iostream>
#include <algorithm>
#include <math.h> 
#include <string>
#include <iomanip>
using namespace std;
int main(){
  int n, a, b;
  cin >> n >> a >> b;
  int max = 0;
  int min = 0;
  if(b > a) max = a;
  else max = b;

  if(a + b > n) min = a + b - n;
  else min = 0;
 
  cout << max << " " << min << endl;
}
  