#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int pow(int x, int n) {
  int i = 0;
  int res = 1;
  while(i != n) {
    res *= x;
    i++;
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  int a[n];
  int odd = 0;
  int even = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    if(a[i] % 2 == 1) {
      odd++;
    }else {
      even++;
    }
  }
  cout << pow(3,n) -pow(2,even) << endl;
  return 0;
}