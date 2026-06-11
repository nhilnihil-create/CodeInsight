#include <bits/stdc++.h>
using namespace std;

int fx(int x) {
  int sum = 0;
  while (x > 0) {
    sum += x % 10;
    x /= 10;
  }
  return sum;
}

int main() {
  int n;
  cin >> n;
  string harshad = "No";
  if (n % fx(n) == 0) harshad = "Yes";//fx
  
  cout << harshad;
}