#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,i;
  cin >> A >> B;
  
  int Pa = 0;

  for (i = 0; i <= B-A; i++) {
    int j = i + A;
    int j1 = j % 10;
    int j2 = j % 100 / 10;
    int j4 = j % 10000 / 1000;
    int j5 = j / 10000;
    if (j1 == j5 && j2 == j4)
      Pa++;
  }
  cout << Pa << endl;
}