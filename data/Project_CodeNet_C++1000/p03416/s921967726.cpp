#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >>B;
  
  int count = 0;
  for (int i = A; i <= B; ++i) {
    int d1, d2, d3, d4, d5, work;
    work = i;
    d5 = work / 10000;
    work %= 10000;
    d4 = work / 1000;
    work %= 1000;
    d3 = work / 100;
    work %= 100;
    d2 = work / 10;
    work %= 10;
    d1 = work / 1;
    if (d5 == d1 && d4 == d2) ++count;
  }
  cout << count << endl;
}