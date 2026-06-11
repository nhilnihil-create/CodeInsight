#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
  int a;
  int b;
  int c;
  int num;
  int count = 0;
  
  cin >> a >> b >> c >> num;
  
  for (int i = 0;i <= a;i++) {
    for (int ii = 0; ii <= b;ii++) {
      for (int iii = 0;iii <= c;iii++) {
        if (500 * i + 100 * ii + 50 * iii == num) {
          count++;
        }
      }
    }
  }
  
  cout << count << endl;
  
  return 0;
}
