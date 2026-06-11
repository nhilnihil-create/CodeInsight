#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  
  int X = B - A;
  int count = 0;
  
  for (int i = 1; i < X; i++) {
    count += i;
  }
  
  cout << count - A << endl;
}