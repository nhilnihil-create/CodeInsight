#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
  int x;
  cin >> x;
  
  int ma = 0;
  if(x == 1) {
    cout << "1" << endl;
    return 0;
  }
  for(int i = 2; i < x; i++) {
    int num = i*i;
    for(int j = 0; ; j++) {
      if(num <= x)
        num *= i;
      else if(j == 0)
        goto Exit;
      else
        break;
    }
    ma = max(ma, num/i);
    Exit:;
  }
  cout << ma << endl; 
}