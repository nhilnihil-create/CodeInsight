#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  int a[3];
  cin >> a[0] >>a[1]>>a[2];
  if(a[0]==a[1]) cout << a[2];
  if(a[0]==a[2]) cout << a[1];
  if(a[2]==a[1]) cout << a[0];
  
}