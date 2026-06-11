#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  int mi = n;
  for(int i = 1; i < n; i++) {
    int a = i;
    int b = n-i;
    int sum = 0;
    while(a > 0) {
      sum += a % 10;
      a /= 10;
    }
    while(b > 0) {
      sum += b % 10;
      b /= 10;
    }
    mi = min(mi, sum);
  }
  cout << mi << endl;
}
